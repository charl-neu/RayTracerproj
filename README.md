# **C++ Raytracing Renderer For GAT350**

## **Introduction**

This project is a high-performance **C++ raytracing renderer** built using **SDL3** for windowing/output and **glm** for mathematical operations.
It is designed as an educational and extensible implementation of real-time and offline rendering concepts, with clean architecture and a focus on simplicity for understandability.

The renderer demonstrates key raytracing techniques while maintaining minimal external dependencies.

---

## **Features**

* **Core Raytracing Pipeline**

  * Primary rays, shadow rays, and reflection rays
* **Lighting & Shading**

  * Diffuse and specular shading
  * different materials materials
* **SDL3 Integration**

  * Efficient pixel buffer output
  * Cross-platform window and event handling
* **glm Mathematics**

  * Vectors, matrices, ray/geometry utilities
* **Clean, Modular C++ Codebase**
  * C++17+
  * Easily extendable scene, materials, and shapes

---

## **Installation**

### **Prerequisites**

Ensure the following tools and libraries are installed:

* **C++20-capable compiler**
* **SDL3**
* **glm**

### **Build Instructions**

```bash
git clone https://github.com/charl-neu/RayTracerproj
cd RayTracerproj

mkdir build
cd build

cmake ..
make
```



## **Usage**

### **Basic Execution**

Running the executable launches the default raytraced scene:

### **Adjusting Settings**

Modify configuration in code 

### **Creating Your Own Scenes**

You can add shapes and materials by editing or extending the scene initialization code in main.cpp
faces until max depth is reached.


---

## **Attribution**

This project uses the following open-source libraries:

* **SDL3** – Simple DirectMedia Layer
* **glm** – OpenGL Mathematics Library


---

## **Conclusion**

This C++ raytracing renderer aims to serve as a clear, incredibly simplistic raytracer setup for my Computer Graphics Class
