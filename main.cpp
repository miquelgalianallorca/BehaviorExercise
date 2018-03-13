// Behavior exercise - Server/View
// Miquel Galiana

#include "stdafx.h"
#include "consola.h"
#include "GameLocalServer.h"
#include "CGameViewLocal.h"

int main()
{
	GameLocalServer localServer;
	CGameViewLocal  localView;
	localServer.InitGame();
	localView.Init(&localServer);

	while (true) {
		localView.Update();
		localServer.Update();
	}

	return 0;
}