#pragma once
#include<iostream>
#include<ctime>


namespace animation {
	class anima {
	public:
		virtual void Update() {
			return;
		}
		virtual void Draw() {
			return;
		}
	};

	class displayer {
	public:
		virtual void Display() {
			return;
		}
	};

	class first_animation :public displayer {
	public:
		void Display();
	};
}