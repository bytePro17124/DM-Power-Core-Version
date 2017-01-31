/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2016 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/

#include "campaign.h"
#include "gen_reward.h"
#include "gen_name.h"
#include "gen_insult.h"
#include "gen_encounter.h"
#include "sdl_graphics.h"
#include "texture.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void load_file(bool &, string &, Campaign &);
void save_file(const bool &, const string &, const Campaign &);

int main(void)
{
	SDL_graphics graphics_engine;
	SDL_Renderer *renderer = graphics_engine.getRenderer();
	int SCREEN_WIDTH = graphics_engine.getScreenWidth();
	int SCREEN_HEIGHT = graphics_engine.getScreenHeight();

	///LOAD SOME FONTS
	//	TTF_Font *Sans;
	//	Sans=TTF_OpenFont("res/fonts/OpenSans-Regular.ttf", 20);
	//	if(!Sans) {
	//		printf("TTF_OpenFont Sans: %s\n", TTF_GetError());
	//	}
	TTF_Font *Verdana;
	Verdana=TTF_OpenFont("res/fonts/Verdana.ttf", 55);
	if(!Verdana) {
		printf("TTF_OpenFont Verdana: %s\n", TTF_GetError());
	}
	TTF_Font *Bookman;
	Bookman=TTF_OpenFont("res/fonts/Bookman.ttf", 30);
	if(!Bookman) {
		printf("TTF_OpenFont Bookman: %s\n", TTF_GetError());
	}

	///LOAD SOME COLORS
	//	SDL_Color Teal = {100, 200, 200, 0};
	SDL_Color White = {255, 255, 255, 0};
	SDL_Color Black = {0,0,0,0};

	///SOLID FULL SCREEN SIZED RECTANCLE FOR A BACKDROP
	SDL_Rect backdropRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	///TITLE TEXT
	string titleText = "TITLE";
	string infoText = "Lorem ipsum dolor sit amet, vocent aliquid similique et eos. Apeirian disputationi duo ea, nemore pericula an has.";

	//		 TTF_SetFontHinting(Verdana, TTF_HINTING_LIGHT);
	//		 TTF_SetFontStyle(Verdana, TTF_STYLE_BOLD);

	TTF_SetFontHinting(Bookman, TTF_HINTING_MONO);

	enum SelectedItem { CHARACTERS = 0, MAGIC_ITEMS, RANDOM_ENCOUNTER, TOOLS, SAVE };
	SelectedItem selectedItem = CHARACTERS;

	Texture defaultScene;
	defaultScene.setRenderer(renderer);
	defaultScene.load("res/pngs/defaultScene.png");

	Texture infoBackground;
	infoBackground.setRenderer(renderer);
	infoBackground.load("res/pngs/defaultInfo.png");

	Texture seperatorBar;
	seperatorBar.setRenderer(renderer);
	seperatorBar.load("res/pngs/seperatorBar.png");

	Texture titleItem1;
	titleItem1.setRenderer(renderer);
	titleItem1.load("res/pngs/charactersMenu.png");

	Texture titleItem2;
	titleItem2.setRenderer(renderer);
	titleItem2.load("res/pngs/defaultItem2.png");

	Texture titleItem3;
	titleItem3.setRenderer(renderer);
	titleItem3.load("res/pngs/defaultItem3.png");

	Texture titleItem4;
	titleItem4.setRenderer(renderer);
	titleItem4.load("res/pngs/defaultItem4.png");

	Texture titleItem5;
	titleItem5.setRenderer(renderer);
	titleItem5.load("res/pngs/defaultItem5.png");

	SDL_Rect subItem = {0,0,144,90};

	Texture beginButton;
	beginButton.setRenderer(renderer);
	beginButton.load("res/pngs/defaultBeginButton.png");


	SDL_Surface *surfaceMessage;

	surfaceMessage = TTF_RenderText_Solid(Verdana, titleText.c_str(), White);
	SDL_Texture *titleArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect titleRect = {830, 65, 550, 115};

	surfaceMessage = TTF_RenderText_Blended_Wrapped(Bookman, infoText.c_str(), Black, 635);
	SDL_Texture *infoArea = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	int w,h;
	w = surfaceMessage->w;
	h = surfaceMessage->h;
	SDL_Rect infoSrcRect = {0, 0, w, h};
	SDL_Rect infoDestRect = {48, 460, w, h};

	SDL_FreeSurface(surfaceMessage);

	bool quit = false;
	SDL_Event e;


	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent (&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					//					if (cursorY > 265) {
					//						cursorY -= cursorIncrement;
					//					}
					break;
				case SDLK_DOWN:
					//					if (cursorY < 685) {
					//						cursorY += cursorIncrement;

					//					}
					break;
				default: break;

				}
			case SDL_MOUSEMOTION:

			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button) {
				case SDL_BUTTON_LEFT: {
					int x = e.button.x;
					int y = e.button.y;
					if ((x > 949 && x < 949+titleItem1.getWidth()) && (y > 230 && y < 230+titleItem1.getHeight())) {
						cout << "Main Item Clicked\n";
					} else if ((x > 825 && x < (825+subItem.w)) && (y > 330 && y < (330+subItem.h))) {
						cout << "Item 2 Clicked\n";
					} else if ((x > 873 && x < (873+subItem.w)) && (y > 420 && y < (420+subItem.h))) {
						cout << "Item 3 Clicked\n";
					} else if ((x > 1201 && x < (1201+subItem.w)) && (y > 420 && y < (420+subItem.h))) {
						cout << "Item 4 clicked\n";
					} else if ((x > 1249 && x < (1249+subItem.w)) && (y > 330 && y < (330+subItem.h))) {
						cout << "Item 5 clicked\n";
					} else if ((x > 960 && x < (960+beginButton.getWidth())) && (y > 620 && y < (620+beginButton.getHeight()))) {
						cout << "Begin Button Clicked\n";
					}
					//					cout << "mouse click at "  << x << ", " << y << "\n";
				}
					break;
				default: break;
				}



			default: break;
			}
			//			if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
			//			{
			//				SDL_Log("Mouse Button 1 (left) is pressed.");
			//			}
		}
		graphics_engine.clear();   //clear screen

		// render black background rect
//		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(renderer, &backdropRect);

		defaultScene.draw(48, 30);

		infoBackground.draw(48, 460);

		seperatorBar.draw(730, 0);

		titleItem3.draw(873, 420, nullptr, &subItem);
		titleItem4.draw(1201, 420, nullptr, &subItem);
		titleItem2.draw(825, 330, nullptr, &subItem);
		titleItem5.draw(1249, 330, nullptr, &subItem);
		titleItem1.draw(949, 230);

		beginButton.draw(960, 620);



		SDL_RenderCopy(renderer, titleArea, NULL, &titleRect);
		SDL_RenderCopy(renderer, infoArea, &infoSrcRect, &infoDestRect);



		graphics_engine.render();
	}


	//	TTF_CloseFont(Sans);
	TTF_CloseFont(Verdana);
	TTF_CloseFont(Bookman);

	//	Sans = NULL;
	Verdana = NULL;
	Bookman = NULL;

















	/// ORIGINAL TERMINAL CODE
	bool loadSuccess = 0;
	string loadedFile = "";
	simpleClearScreen();
	cout << "** && ** Dungeon's & Dragons - 5e Core ** && **" << endl;
	int choice = 0;
	Campaign mygame;
	load_file(loadSuccess, loadedFile, mygame);
	do
	{
		cout << "\n----------MAIN MENU----------\n"
			 << "1. Characters\n"
			 << "2. Magic Items, Spells, Rewards, Etc\n"
			 << "3. Experience Calculator\n"
			 << "4. Name Generator\n"
			 << "5. Random Encounter\n"
			 << "6. NPC Insult\n"
			 << "7. Save & Quit\n"
			 << "8. Quit\n"
			 << "-----------------------------\n"
			 << endl;
		choice = getNumber("Choice: ", 1, 8);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (choice)
		{
		case 1:
			mygame.pc_menu();
			break;
		case 2:
		{
			Magic_Items gen;
			gen.treasure_menu();
		}
			break;
		case 3:
		{
			Magic_Items gen;
			float rewardXP = gen.xpgenerator();
			simpleClearScreen();
			cout << "XP per member = " << rewardXP << "\n\n";
		}
			break;
		case 4:
		{
			CharacterName randomName;
			simpleClearScreen();
			cout << "Here is a name: " << randomName.grabRandomName() << "\n\n";
		}
			break;
		case 5:
		{
			Encounter encounter;
			simpleClearScreen();
			cout << encounter.Gen_Encounter();
			pressEnterToContinue();
		}
			break;
		case 6:
		{
			Insult insult;
			simpleClearScreen();
			cout << "Maybe this will make the PCs mad: " << insult.laydownheat() << "\n\n";
		}
			break;
		case 7:
			save_file(loadSuccess, loadedFile, mygame);
		case 8:
			cout << "Exiting Program.\n";
		default:
			break;
		}
	} while (choice < 7);
	return EXIT_SUCCESS;
}
void load_file(bool &ls, string &lf, Campaign &game)
{
	string file;
	ifstream thefile;
	cout << "Load File: ";
	getline(cin, file, '\n');
	thefile.open(("saves/" + file + ".save").c_str());
	if (thefile.is_open())
	{
		game.retrieveCharacter(thefile);
		simpleClearScreen();
		cout << "File '" << file << "' loaded.\n\n";
		ls = true;
		lf = file;
		thefile.close();
	}
	else
	{
		simpleClearScreen();
		cout << "No file named '" << file << "'. Starting new file.\n\n";
	}
}
void save_file(const bool &ls, const string &lf, const Campaign &game)
{
	string file;
	ofstream os;
	if (ls == false)
	{
		cout << "Save As: ";
		getline(cin, file, '\n');
	}
	else
	{
		file = lf;
	}
	//save into file after above is complete
	os.open(("saves/" + file + ".save").c_str());
	if (os.is_open())
	{
		game.dumpCharacter(os);
		cout << "All data saved in file -> " << file << endl;
		os.close();
	}
	else
	{
		cout << "Save failed.\n";
	}
}
