#include "XML.h"


void XML::setAtribute(DynamicString atribute)
{
	this->atribute = atribute;
}

void XML::setTag(DynamicString tag)
{
	this->tag = tag;
}

DynamicString XML::getAtribute()const
{
	return this->atribute;
}

DynamicString XML::getTag() const
{
	return this->tag;
}

void XML::addChild(XML child)
{
	children.addLast(child);
}


List<XML> XML::getChild()
{
	return children;
}
XML::XML(DynamicString tag, DynamicString atribute)
{
	setTag(tag);
	setAtribute(atribute);
}

void XML::setTagsAllChildren(DynamicString tag, DynamicString newTag)
{
	size_t size = children.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		if (tag == children[i].getTag())
		{
			children[i].setTag(newTag);
		}
	}
}


void XML::cutPath(DynamicString& path)
{
	bool cut = false;
	char* _pData;
	size_t counter = 0;
	size_t size = path.size();
	for (size_t i = 0; i<size; ++i)
	{
		if (cut)
		{
			_pData[counter] = path[i];
			++counter;
		}

		if (!cut && path[i] == '/')
		{
			cut = true;
			_pData = new char[path.size() - i + 1];
		}

	}
	_pData[counter] = '\0';
	path = _pData;
	delete _pData;
}
DynamicString XML::getTag(DynamicString& path, bool& end)
{
	char* _pData;
	size_t counter = 0;
	size_t size = path.size();
	end = false;
	for (size_t i = 0; path[i] != '/' && i<size; ++i)
	{
		++counter;
		if (i + 1 == size)
		{
			end = true;
		}
	}
	_pData = new char[counter];
	_pData[counter] = '\0';


	for (size_t i = 0; i < counter; ++i)
	{
		_pData[i] = path[i];
	}
	return _pData;
}


void XML::setTag(DynamicString path, DynamicString newTag)
{
	bool end = false;
	DynamicString _tag = getTag(path, end);
	if (end)
	{
		if (this->tag == _tag)
		{
			setTag(newTag);
		}
		else
		{
			throw "Wrong path";
		}
		
	}
	else
	{
		cutPath(path);
		size_t size = children.getSize();
		_tag = getTag(path, end);
		for (size_t i = 0; i < size; ++i)
		{
			
			if (children[i].getTag() == _tag)
			{
				children[i].setTag(path, newTag);
			}
			
		}

	}
}

void XML::setAtribute(DynamicString path, DynamicString atribute)
{

	bool end = false;
	DynamicString _tag = getTag(path, end);
	if (end)
	{
		if (this->tag == _tag)
		{
			setAtribute(atribute);
		}
			else
			{
				throw "Wrong path";
			}

	}
	else
	{
		cutPath(path);
		size_t size = children.getSize();
		_tag = getTag(path, end);
		for (size_t i = 0; i < size; ++i)
		{

			if (children[i].getTag() == _tag)
			{
				children[i].setAtribute(path, atribute);
			}

		}

	}
}

void XML::addTag(DynamicString path, DynamicString tag)
{

	bool end = false;
	DynamicString _tag = getTag(path, end);
	if (end)
	{
		if (this->tag == _tag)
		{
			XML newXML(tag, "");
			children.addLast(newXML);
		}
			else
			{
				throw "Wrong path";
			}

	}
	else
	{
		cutPath(path);
		size_t size = children.getSize();
		_tag = getTag(path, end);
		for (size_t i = 0; i < size; ++i)
		{

			if (children[i].getTag() == _tag)
			{
				children[i].addTag(path, tag);
			}

		}

	}

}

void XML::deleteTag(DynamicString path)
{

	bool end = false;
	DynamicString _tag;
		cutPath(path);
		size_t size = children.getSize();
		_tag = getTag(path, end);
		for (size_t i = 0; i < size; ++i)
		{

			if (children[i].getTag() == _tag && end)
			{
				children.removeAt(i);
			}
			else if (children[i].getTag() == _tag){
				children[i].deleteTag(path);
			}

		}

}

void XML::deleteAtribute(DynamicString path)
{

	bool end = false;
	DynamicString _tag;
	cutPath(path);
	size_t size = children.getSize();
	_tag = getTag(path, end);
	for (size_t i = 0; i < size; ++i)
	{

		if (children[i].getTag() == _tag && end)
		{
			children[i].setAtribute("");
		}
		else if (children[i].getTag() == _tag){
			children[i].deleteAtribute(path);
		}
	}

}

void XML::printXML()
{

	print(1);
}

void XML::print(size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		std::cout << "    ";
	}
	std::cout << "<" << this->tag << ">" << std::endl;
		
	for (size_t i = 0; i < count+1; ++i)
	{
		std::cout << "    ";
	}
	std::cout<< this->atribute << std::endl;
	size_t size = children.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		children[i].print(count+1);
	}

	for (size_t i = 0; i < count; ++i)
	{
		std::cout << "    ";
	}
	std::cout << "</" << this->tag << ">" << std::endl;
}
void XML::printOS(std::ostream& os, size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		os << "    ";
	}
	os << "<" << this->tag << ">" << std::endl;

	for (size_t i = 0; i < count + 1; ++i)
	{
		os << "    ";
	}
	os << this->atribute << std::endl;
	size_t size = children.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		children[i].print(count + 1);
	}

	for (size_t i = 0; i < count; ++i)
	{
		std::cout << "    ";
	}
	os << "</" << this->tag << ">" << std::endl;
}
void XML::printXML2()
{

	std::cout << "<" << this->tag << " >\n" << this->atribute << std::endl;
	size_t size = children.getSize();
	for (size_t i = 0; i < size; ++i)
	{
		children[i].printXML2();
	}

	std::cout << "</" << this->tag << ">" << std::endl;
}

XML& XML::getXML()
{
	return *this;
}

