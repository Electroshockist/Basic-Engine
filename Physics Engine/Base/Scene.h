#pragma once
struct Scene {
	const bool OnCreate();
	const bool Render() const;
	const bool Update(unsigned int fps);
};

