#include <time.h>
#include <algorithm>
#include "game_main.h"
#include "../dxlib_ext/dxlib_ext.h"
#include<vector>

bool init = false;
//int count = 0;
int Point = 0;
const int MAX = 10;
int OK = 0;
int Miss = 0;

bool result[MAX] = {};

std::vector<bool>resultList;
int hoge = 0;

float count = 0;
const float TIMER = 1;

void gameMain(float delta_time) {

	if (!init) {
		srand(time(0));
		init = true;
	}
	//Max = 5;
	DrawStringEx(100, 100, -1, "成功%d、ミス%d", Point, Miss);
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT)) {
		
		hoge = 0;
		for (int i = 0; i < MAX; i++) {
			//OK = rand() % 100; //この処理を指定回数繰り返したい上で一回一回結果を表示したい
			OK = GetRand(1000);

			if (OK <= 500) {
				//Point++;
				resultList.emplace_back(true);
			}
			if (OK >= 500) {
				//Miss++;
				resultList.emplace_back(false);
			}

			//count++;

			/*WaitTimer(1000);*/
		}
	}

	if (resultList.empty())return;

	//少しずつflame秒を足す
	count += delta_time;

	if (count > TIMER) {
		count = 0;

		if (hoge >= MAX) {
			Point = 0;
			Miss = 0;
			return;
		}

		//配列の中身を一つずつ見て行き、時間ごとに更新する
		if (resultList[hoge] == true) {
			Point++;
		}
		else {
			Miss++;
		}
		if (hoge < MAX)hoge++;
	}






	/*for (int i = 0; i < resultList.size(); ++i) {
		if (resultList[i] == true) {
			DrawStringEx(100, 100 + i * 20, -1, "true");
		}
		else {
			DrawStringEx(100, 100 + i * 20, -1, "false");
		}
	}*/

}

