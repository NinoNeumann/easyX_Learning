#include "animation.hpp"
#include "global.hpp"
#include <graphics.h>



int main() {

	animation::first_animation first;
	first.Display();
	loadimage(& animation::logo, _T("D:/ChromDownload/firework/firework/firework/res_1.png"));
	/*initgraph(400, 600);
	IMAGE logo;
	loadimage(&logo, _T("D:/ChromDownload/firework/firework/firework/res_1.png"), 100, 50);
	putimage(0, 0, &logo, SRCINVERT);
	getchar();
	closegraph();*/
	
	return 0;


}