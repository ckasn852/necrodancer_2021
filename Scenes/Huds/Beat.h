#pragma once
enum BeatState
{
	eAllStop, eBeatEnd, ePlayerCanMove, eBeatStart
};

class Beat
{
public:
	Beat();
	~Beat();

	BeatState GetBeatState() { return beatState; }

	void Position(D3DXVECTOR2& cameraPo);
	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
	void MissRender();

	void MissBeat(D3DXVECTOR2& cameraPo) { bMiss = true; missSprite->Position(cameraPo.x, cameraPo.y - beatPoY + missTimer * SCALE*GRID);; }
	bool GetMissBeat() { return bMiss; }

private://beatLine
	struct BeatLine
	{
		Sprite* beatLine;
		bool bDirection;//left==false
		float XShift = 0;
		bool operator <(BeatLine& a)
		{
			return beatLine->Position().x < a.beatLine->Position().x;
		}
	};
	
	float beatStartSpot = 80;
	float beatEndSpot = 10;
	D3DXVECTOR2 cameraPo;
private:
	BeatState beatState = eAllStop;
	float currentBeatPoX = 0;

private:
	Sprite* missSprite;
	bool bMiss = 0;
	float missTimer = 0;
private:
	vector<BeatLine> beatLines;
};