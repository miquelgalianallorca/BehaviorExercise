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
		localServer.Update();
		localView.Update();
	}

	return 0;
}