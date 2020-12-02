#pragma once
enum StringName
{
	eX
};

class Word
{
public:
	Word();
	~Word();

	Sprite* Number(BYTE num); 
	Sprite* GetString(StringName name) { return strings[name]; }
private:
	Sprite* numbers[10];
	vector<Sprite*> strings;
	
};