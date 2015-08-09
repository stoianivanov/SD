#pragma once 
#include <string>
#include "List.h"
#include "DynamicString.h"
class XML
{
public:
	XML(DynamicString tag = "", DynamicString atribute="");


	void setTag(DynamicString tag);
	void setAtribute(DynamicString atribute);
	DynamicString getTag()const;
	DynamicString getAtribute() const;
	void addChild(XML);
	List<XML> getChild();
	void setTagsAllChildren(DynamicString ,DynamicString);
	void setTag(DynamicString path, DynamicString tag);
	void setAtribute(DynamicString path, DynamicString atribute);
	void addTag(DynamicString path, DynamicString tag);
	void addAtribute(DynamicString path, DynamicString atribute);
	void deleteTag(DynamicString path);
	void deleteAtribute(DynamicString path);
	void cutPath(DynamicString& path);
	DynamicString getTag(DynamicString& path, bool&);
	void printXML();
	void printXML2();
	XML& getXML();	
	void printOS(std::ostream& os, size_t);
private:
	void print(size_t);


private:
	DynamicString tag;
	DynamicString atribute;
	List<XML> children;
};

