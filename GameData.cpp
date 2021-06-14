#include "GameData.h"

GameData::GameData(std::string _songTitle, std::string _composerName, 
	std::string _songFilePath, std::vector<Beats> _BeatData)
{
	this->songTitle = _songTitle;
	this->composerName = _composerName;
	this->songFilePath = _songFilePath;
	this->BeatData = _BeatData;
}

GameData::~GameData()
{

}
