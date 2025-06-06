#pragma once

#include <vector>
#include <memory>
#include <../imgui/imgui.h>


#include "Entities.hpp"
#include "Renderer/src/Shader.hpp"
#include"ComponentManager.hpp"

//DEBUG



struct scene_node {
    ENTITY entity;
    std::vector<scene_node*> Childrens;  // Use raw pointers for performance

    scene_node(const ENTITY& te) : entity(te) {}

    void addChild(scene_node* child) {
        Childrens.push_back(child);
    }
};

namespace eng{
    class SceneManager {
    private:
        EntitiesIDGenerator id_generator;
        std::shared_ptr<ComponentManager> Component_UNIT;
        scene_node* e_Root;
        Shader* SHADER;


        void setPropsforDynamic() {

        }

        

    public:
        SceneManager()
            : id_generator(), Component_UNIT(), e_Root(nullptr) {

            Component_UNIT = std::make_shared<ComponentManager>();
        }
        ~SceneManager() {
            deleteScene(e_Root);
        }
        scene_node* findNodeByID(scene_node* node, uint32_t id) {
            if (!node) return nullptr;
            if (node->entity.id == id) return node;

            for (auto* child : node->Childrens) {
                scene_node* result = findNodeByID(child, id);
                if (result) return result;
            }
            return nullptr;
        }
        // Create entity with raw pointers for performance
        void createEntity(entities_type l_type, std::string shapeName_or_path, uint32_t parent_id = 0, size_t num_instnace = 1 )
        {
            // Allocate scene_node on the stack for better performance
            ENTITY temp = ENTITY(id_generator.create_id(), l_type);
            //std::cout << temp.id << "\n";
            scene_node* parent_scene = findNodeByID(e_Root, parent_id);
            // Mark entry with temp entity
            Component_UNIT->markEntry(temp, shapeName_or_path, num_instnace);

            scene_node* new_node = new scene_node(temp);

            if (!e_Root) {
                e_Root = new_node;  // Set the root
            }
            else {
                parent_scene->addChild(new_node);
            }

        }

        void loadModel(const std::string& name,const std::string& path) {
            Component_UNIT->s_library.addShapeData(name, path);
        }
        void drawNode(scene_node* node, int32_t& selected_id) {
            if (!node) return;

            std::string label = "Entity " + std::to_string(node->entity.id);
            ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
            if (node->entity.id == selected_id)
                flags |= ImGuiTreeNodeFlags_Selected;

            ImGui::SetNextItemOpen(true, ImGuiCond_Always); // Always expanded
            if (ImGui::TreeNodeEx((void*)(intptr_t)node->entity.id, flags, "%s", label.c_str())) {

                if (ImGui::IsItemClicked()) {
                    if (selected_id == node->entity.id)
                        selected_id = -1; // Deselect
                    else
                        selected_id = node->entity.id;
                }

                for (auto* child : node->Childrens)
                    drawNode(child, selected_id);

                ImGui::TreePop();
            }
        }



        int32_t IMGUI_SCENE_PROPS() {
            static int32_t current_imgui_selected_ent = -1;
            ImGui::BeginChild("ComponentBox", ImVec2(0, 150), true);
            ImGui::Text("SCENE MANAGER");
            drawNode(e_Root,current_imgui_selected_ent);
            ImGui::EndChild();
            
            Component_UNIT->IMGUI_COMP_PROPS(current_imgui_selected_ent);
            return current_imgui_selected_ent;
        }
        //Later JOB
        void Update_Scene(float deltaTime) {

        }
        std::shared_ptr<ComponentManager> getComponent2GPU() {
            return Component_UNIT;
        }
    private:
        // Recursive function to free all nodes
        void deleteScene(scene_node* node) {
            if (!node) return;
            for (auto* child : node->Childrens) {
                deleteScene(child);
            }
            delete node;
        }

    };
}
