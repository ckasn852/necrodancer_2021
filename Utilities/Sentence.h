#pragma once
enum SentenceName
{

};

class Sentence
{
public:
	Sentence();
	~Sentence();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

private:
	vector<Sprite*> sentences;
};