#include "entity.h"

Entity::Entity(float temp_x, float temp_y, float vel,  float temp_w, float temp_h) //constructors
{
	x = temp_x;
	y = temp_y;
	width = temp_w;
	height = temp_h;
	velocity = vel;
}
Entity::Entity()
{
	x = 250;
	y = 800;
	width = 50;
	height = 50;
	velocity = 2;
}

Entity::Entity(float temp_x, float temp_y, float vel)
{
	x = temp_x;
	y = temp_y;
	width = 50;
	height = 50;
	velocity = vel;
}

void Entity::draw() //klhronomeitai apo upoklaseis, xrhsimopoieitai gia na zwgrafisei ta entities
{

}

void Entity::update() //idio me draw, kanei update th thesh twn entities
{

}

bool Entity::borderCheck() // klhronomeitai, gyrizei true otan to entity vrisketai konta (px playerplane) h eksw (px projectile) apo thn othonh tou player
{
	return false;
}

float Entity::distanceToCorner()
{
	return pow(pow(height, 2) + pow(width, 2), 0.5) / 2;
}

float Entity::getX()
{
	return x;
}
float Entity::getY()
{
	return y;
}
float Entity::getHeight()
{
	return height;
}
float Entity::getWidth()
{
	return width;
}