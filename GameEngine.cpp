#include "GameEngine.h"
#include "StateSplashScreen.h"

GameEngine::GameEngine(int p_width, int p_height, std::string p_title)
{
	m_data = std::make_shared<GameData>();

	this->m_data->stateMachine.AddState(StateRef(new StateSplash(this->m_data)));

	this->m_data->window.create(sf::VideoMode((unsigned)p_width, (unsigned)p_height), p_title, sf::Style::Default);
	this->m_data->window.setFramerateLimit(60);
}

GameEngine::~GameEngine() {}

void GameEngine::Run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->m_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->m_data->window.isOpen())
	{
		this->m_data->stateMachine.ProcessStateChanges();

		newTime = this->m_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->m_data->stateMachine.GetActiveState()->HandleInput();
			this->m_data->stateMachine.GetActiveState()->Update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->m_data->stateMachine.GetActiveState()->Draw(interpolation);
	}
}

GameData::GameData()
{
}

GameData::~GameData()
{
}
