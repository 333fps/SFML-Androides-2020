#include "AndroidDemo.h"

AndroidDemo::AndroidDemo(GameDataRef p_data, sf::Vector2f& p_startPosition, std::vector<std::string>& p_path,
	std::unique_ptr<std::vector<std::string>>& p_level)
	: Sprite(p_data, p_startPosition, p_path, p_level)
{
}

AndroidDemo::~AndroidDemo()
{
}

void AndroidDemo::NextMotion()
{
	if (m_presentPosition.y == 8.0f)
	{
		if (m_presentPosition.x != 624.0f)
		{
			m_nextPosition.x = m_presentPosition.x + 16.0f;
		}

		if (m_presentPosition.x == 624.0f)
		{
			m_nextPosition.y = m_presentPosition.y + 8.0f;
		}
	}

	if (m_presentPosition.x == 624.0f)
	{
		if (m_presentPosition.y == 8.0f)
		{
			m_nextPosition.y = m_presentPosition.y + 8.0f;
		}

		if (m_presentPosition.y == 328.0f)
		{
			m_nextPosition.x = m_presentPosition.x - 16.0f;
		}
	}

	if (m_presentPosition.y == 328.0f)
	{
		if (m_presentPosition.x != 0.0f)
		{
			m_nextPosition.x = m_presentPosition.x - 16.0f;
		}

		if (m_presentPosition.x == 0.0f)
		{
			m_nextPosition.y = m_presentPosition.y - 8.0f;
		}
	}

	if (m_presentPosition.x == 0)
	{
		if (m_presentPosition.y != 8.0f)
		{
			m_nextPosition.y = m_presentPosition.y - 8.0f;
		}

		if (m_presentPosition.y == 8.0f)
		{
			m_nextPosition.x = m_presentPosition.x + 16.0f;
		}
	}
}

void AndroidDemo::Update(float p_deltaTime)

{
	m_totalTime += p_deltaTime;
	m_presentPosition = m_spriteShape.getPosition();

	if (m_presentPosition.y == 24.0f && m_presentPosition.x != 624.0f)
	{
		m_nextPosition.y = 8.0f;
	}

	if (m_presentPosition.x == 16.0f && m_presentPosition.y != 8.0f && m_presentPosition.y != 328.0f)
	{
		m_nextPosition.x = m_presentPosition.x - 16.0f;
	}

	if (m_totalTime > m_dtMax)
	{
		if (!m_isFalling)
		{
			NextMotion();
			if (!IsInBounds())
				m_nextPosition = m_presentPosition;
			if (!IsOnPath())
				m_nextPosition = m_presentPosition;
			if (m_isInWall)
				m_nextPosition.y = m_presentPosition.y - 8.0f;
		}
		else
		{
			m_nextPosition.y = m_presentPosition.y + 8.0f;
		}
		UpdateStatus();

		m_totalTime = 0;
	}

	m_spriteShape.setPosition(m_nextPosition);
}
