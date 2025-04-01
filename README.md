# **Asthrasine**  
_A High-Performance Game Engine using OpenGL 4.5_  

Asthrasine is a modern, high-performance game engine built on **OpenGL 4.5**, designed for real-time rendering with a flexible **Entity-Scene Component (ESC) system**. It integrates **ImGui** for a powerful, real-time UI and features a **graph-like scene manager** for efficient entity handling. The engine supports **dynamic lighting with real-time UI adjustments**, making it an ideal foundation for game development, simulation, and visualization projects.  

## **Key Features**  

✅ **OpenGL 4.5 Renderer** – Modern rendering pipeline for efficient, high-quality rendering.  
✅ **ESC-Based Scene Management** – Graph-like entity management for optimal flexibility and performance.  
✅ **Four Entity Types** – Static, Dynamic, Instanced, and Light entities for structured scene representation.  
✅ **Dynamic Lighting System** – Real-time adjustable lights through UI, enhancing scene realism.  
✅ **ImGui Integration** – Live UI controls for modifying rendering parameters and debugging.  
✅ **SSBO Optimization** – Efficient storage of transformation matrices for high-performance rendering.  
✅ **GLAD, GLFW, and GLM** – Industry-standard libraries for modern OpenGL development.  

---

## **Project Architecture**  

Asthrasine is structured into several core modules to maintain clean, scalable, and efficient code:  

### 1️⃣ **Rendering System**  
- Uses **OpenGL 4.5** with a forward or deferred rendering pipeline.  
- Implements **Shader Storage Buffer Objects (SSBOs)** for handling large amounts of dynamic data.  
- Supports real-time dynamic lighting.  

### 2️⃣ **Entity-Scene Component (ESC) System**  
- Unlike traditional ECS, Asthrasine uses a **graph-based scene structure** for managing objects.  
- Four main entity types:  
  - **Static Entities** – Non-moving objects like terrain, walls, and static models.  
  - **Dynamic Entities** – Objects with physics, animations, or user-controlled movement.  
  - **Instanced Entities** – Optimized for repeated models (e.g., trees, crowds, particles).  
  - **Light Entities** – Control dynamic lighting effects (directional, point, and spotlights).  

### 3️⃣ **UI System (ImGui)**  
- Live parameter tweaking for materials, lighting, and rendering settings.  
- Debugging tools to monitor frame rates, entity properties, and shaders.  

### 4️⃣ **Scene Manager**  
- Stores entities in a **hash map + flat map hybrid** for fast lookups.  
- Implements an **Entity Factory** to streamline entity creation and deletion.  
- Uses **SSBOs for dynamic model matrices**, allowing high-performance instanced rendering.  

---

## **Technology Stack**  

| Library | Purpose |  
|---------|---------|  
| **OpenGL 4.5** | High-performance rendering API |  
| **GLAD** | OpenGL function loader |  
| **GLFW** | Window management and input handling |  
| **GLM** | Mathematics library for graphics applications |  
| **ImGui** | Immediate Mode GUI for real-time debugging and UI |  

---

## **Installation & Setup**  

### **Prerequisites**  
- C++ compiler (g++ or Clang recommended)  
- OpenGL 4.5+ supported GPU  
- **CMake** (for building the project)  

### **Build Instructions**  
```sh
git clone https://github.com/yourusername/Asthrasine.git
cd Asthrasine
mkdir build && cd build
cmake ..
make
./Asthrasine
```

---

## **Learning Resources**  

To better understand OpenGL and game engine development, check out these resources:  

📌 **The Cherno Game Engine Series** – [YouTube](https://www.youtube.com/c/TheCherno) – Covers advanced game engine architecture.  
📌 **OGLDev** – [OGLDev Website](http://ogldev.org/) – Detailed tutorials on OpenGL and graphics programming.  
📌 **LearnOpenGL** – [LearnOpenGL Website](https://learnopengl.com/) – Covers modern OpenGL techniques.  

---

## **Future Plans**  

🚀 **Physics Engine** – Integrate collision detection and physics simulation.  
🚀 **Deferred Rendering** – Implement an optimized rendering pipeline for complex scenes.  
🚀 **Vulkan Backend** – Add Vulkan support for next-gen rendering.  

---

## **Contributing**  

Want to improve Asthrasine? Feel free to fork, contribute, or discuss new features!  

```sh
git checkout -b feature-branch
git commit -m "Add cool feature"
git push origin feature-branch
```

---

## **License**  

📜 This is just an personal project for me hook me for any thing ...
