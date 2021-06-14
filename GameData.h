#pragma once

#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <iostream>
#include <string>
#include <vector>
#include "Graphics.h"

class GameData
{
public:
	std::string songTitle;
	std::string composerName;
	std::vector<Beats> BeatData;
	std::string songFilePath;
public:
	GameData(std::string _songTitle, std::string _composerName, 
		std::string _songFilePath, std::vector<Beats> _BeatData);
	~GameData();
};

class PointData {
public:
	long int points;
	int long_combo, good, bad, ok;
	
	PointData(int _points = 0, int _long_combo = 0, int _good = 0, int _bad = 0, int _ok = 0) :
		points(_points), 
		long_combo(_long_combo), 
		good(_good),
		ok(_ok),
		bad(_bad)
	{};
};

#endif