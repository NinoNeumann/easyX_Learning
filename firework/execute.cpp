#include "animation.hpp"
#include "global.hpp"
#include <graphics.h>



int main() {

	animation::first_animation first;
	first.Display();
	loadimage(& animation::logo, _T("D:/ChromDownload/firework/firework/firework/res_1.png"));
	
	
	return 0;


}