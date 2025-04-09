#pragma once

#include <vector>
#include <memory>


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
        void createEntity(entities_type l_type, std::string shapeName, uint32_t parent_id = -1, size_t num_instnace = 1 ,const glm::mat4& model=glm::mat4(1.0f))
        {
            // Allocate scene_node on the stack for better performance
            ENTITY temp = ENTITY(id_generator.create_id(), l_type);
            std::cout << temp.id << "\n";
            scene_node* parent_scene = findNodeByID(e_Root, parent_id);
            // Mark entry with temp entity
            Component_UNIT->markEntry(temp, shapeName, num_instnace, model);

            scene_node* new_node = new scene_node(temp);

            if (!e_Root) {
                e_Root = new_node;  // Set the root
            }
            else {
                parent_scene->addChild(new_node);
            }

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
