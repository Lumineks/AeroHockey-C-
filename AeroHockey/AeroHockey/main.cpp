#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
private:
	double x;
	double y;
	double height;
	double width;
	double dx;
	double dy;
	double speed;
	int direction;
	std::string file;
	Image image;
	Texture texture;
	Sprite sprite;

public:
	Player(std::string file, int x, int y, double w, double h)
	{
		this->file = file;
		this->width = w;
		this->height = h;
		image.loadFromFile("images/" + this->file);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		this->x = x;
		this->y = y;
		sprite.setTextureRect(IntRect(0, 0, w, h));
		direction = 0;
		speed = 0;
	}

	Sprite GetSprite() { return sprite; }
	double GetX() { return x; }
	double GetY() { return y; }

	void Update(double time)
	{
		switch (direction)
		{
		case 0:
			dx = speed;
			dy = 0;
			break;
		case 1:
			dx = -speed;
			dy = 0;
			break;
		case 2:
			dx = 0;
			dy = speed;
			break;
		case 3:
			dx = 0;
			dy = -speed;
			break;
		}
		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
	}
};

int main()
{
	RenderWindow window(sf::VideoMode(880, 460), "Air Hockey");

	Player player("hero.png", 250, 250, 129.0, 129.0);

	Clock clock;

	while (window.isOpen())
	{
		double time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(player.GetSprite());
		window.display();
	}

	return 0;
}