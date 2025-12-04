#include "Renderer.h"
#include "Framebuffer.h"
#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"
#include "Random.h"
#include <memory>

#include <iostream>

int main() {
	constexpr int SCREEN_WIDTH = 800;
	constexpr int SCREEN_HEIGHT = 600;

	// create renderer
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Ray Tracer", SCREEN_WIDTH, SCREEN_HEIGHT);

	Framebuffer framebuffer(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

	float aspectRatio = static_cast<float>(SCREEN_WIDTH) / static_cast<float>(SCREEN_HEIGHT);
	Camera camera(70.0f, aspectRatio);
	camera.SetView({ 0,0,5 }, { 0,0,0 });

	Scene scene;


	scene.SetSky({ 0.5f, 0.7f, 1.0f }, { 1.0f, 1.0f, 1.0f });

	for (int i = 0; i < 5; i++) {
		glm::vec3 position = glm::vec3{
			getReal(-3.0f, 3.0f),
			getReal(-2.0f, 2.0f),
			getReal(-1.0f, 1.0f)
		};
		
		std::unique_ptr<Sphere> sphere = std::make_unique<Sphere>(Sphere(position, 0.5f, getRealVec3({ 0,0,0 }, { 1,1,1 })));

		scene.AddObject(std::move(sphere));
	}


	SDL_Event event;
	bool quit = false;
	while (!quit) {
		// check for exit events
		while (SDL_PollEvent(&event)) {
			// window (X) quit
			if (event.type == SDL_EVENT_QUIT) {
				quit = true;
			}
			// escape key quit
			if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE) {
				quit = true;
			}
		}

		// draw to frame buffer
		framebuffer.Clear({ 0, 0, 0, 255 });
		
		scene.Render(framebuffer, camera);

		// update frame buffer, copy buffer pixels to texture
		framebuffer.Update();

		// copy frame buffer texture to renderer to display
		renderer.CopyFramebuffer(framebuffer);
		renderer.Show();
	}
}