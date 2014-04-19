#pragma once

#include <functional>
#include "Common.h"
#include "Textbox.h"
#include "StringConverter.h"

class TextItem
{
public:
	TextItem(Textbox* owner, void (*action_callback)() = 0, string text = 0, unsigned char index = 0, unsigned int value = 0)
	{
		this->owner_textbox = owner;
		//for this stupid block of code, see Textbox.cpp
		if(action_callback)
			this->callback = action_callback;
		else
			this->callback = nullptr;
		this->text = text;
		this->index = 0;
		this->value = 0;

		pokestring(this->text);
	}

	~TextItem()
	{
	}

	void Action()
	{
		if (callback != nullptr)
			callback();
	}

	void SetText(const std::string& to)
	{
		this->text = to;
		pokestring(this->text);
	}

	string& GetText() { return text; }

	string text; //the text that the item displays
	unsigned char index; //the slot of the item
	unsigned int value; //the value on the item (used for items)

private:
	Textbox* owner_textbox;
	std::function<void()> callback; //the function that gets called when the item is selected
};