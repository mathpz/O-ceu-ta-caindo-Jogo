#include <sfml\Graphics.hpp>
#include <iostream> 
#include <stdio.h>
#include  "Animation.h"
#include "Player.h"
#include "Platform.h"
#include <vector>
#include "Stage.h"
#include "Menu.h"
#include "Jogo.h"


using namespace std;


int main()
{
	srand(time(NULL));

	Jogo jogo;
	jogo.exec();
	
	return 0;
}

