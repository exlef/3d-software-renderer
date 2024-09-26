# Software Renderer Prototype


https://github.com/user-attachments/assets/99a9456f-f47a-4436-84f1-8272fb16bba4



https://github.com/user-attachments/assets/1d0cf451-5b5b-4bb6-8676-5596f9c406ce


## Introduction
This project is a software renderer prototype developed as a learning exercise. It implements basic 3D rendering techniques without relying on hardware acceleration, providing insights into the fundamentals of computer graphics.

## Features

- Custom software-based 3D rendering pipeline
- OBJ file loading for 3D models
- Texture mapping with perspective correction
- Basic camera system with movement and rotation
- Back-face culling for improved performance
- Z-buffer implementation for proper depth handling

## Dependencies

- [raylib](https://www.raylib.com/): Used for window creation and basic input handling

## Project Structure

- `main.cpp`: Entry point of the application, sets up the window and main rendering loop
- `model_loader.h`: Handles loading 3D models from OBJ files
- `rendering.h`: Contains the core rendering logic, including the custom software renderer

## How It Works

1. The application loads a 3D model from an OBJ file.
2. In each frame, the renderer:
   - Transforms model vertices from object space to world space
   - Applies camera transformations to convert vertices to camera space
   - Projects 3D points onto a 2D screen space
   - Rasterizes triangles with perspective-correct texture mapping
   - Applies z-buffering for proper depth handling

## Future Improvements

- Implement shading models (e.g., Phong shading)
- Add support for lighting
- Optimize performance for larger scenes
- Implement more complex 3D models and scenes

## Learning Objectives

This project serves as a practical exploration of:
- 3D graphics pipeline stages
- Vector and matrix operations in 3D space
- Rasterization techniques
- Texture mapping and perspective correction
- Basic optimizations in software rendering

## Acknowledgements

This project uses the raylib library for window management and basic utilities.

I also used below sources to learn about this topic
   - https://gabrielgambetta.com/computer-graphics-from-scratch/
   - https://www.youtube.com/watch?v=CX6cjV2FIgQ (for .obj loading)
   - https://www.youtube.com/watch?v=k5wtuKWmV48

