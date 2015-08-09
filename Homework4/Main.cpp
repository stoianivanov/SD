#include <iostream>
#include "DynamicString.h"
#include "List.h"
#include "XML.h"


int main()
{
	/*
	DynamicString path;
	getline(std::cin, path);
	XMLTree tree;
	XML root("root", "atribute");
	std::cout << root.getTag() << std::endl;
	DynamicString tag = tree.getTag(path);
	std::cout << "XML root == path" <<( tag == root.getTag() )<< std::endl;
	tree.cutPath(path);
	std::cout << "cut PAth" << path << std::endl;
	tree.addChild(root);
	List<XML> list = tree.getChildren();
	std::cout << list.getSize() << std::endl;
	*/
	/*
	XML root("root", "atribute1");
	XML child("Child", "stoqn");
	root.addChild(child);
	List<XML> list2 = root.getChild();
	std::cout << list2[0].getTag() << std::endl;
	root.setTagsAllChildren("Child", "child");
	List<XML> list = root.getChild();
	std::cout << list[0].getTag() << std::endl;
	*/

	XML root("root", "mrazq");
	XML child("child", "obicham");
	root.addChild(child);
	root.setTag("root/child", "CHild");
	List<XML> list = root.getChild();
	std::cout << list[0].getTag() << std::endl;

	XML child2("child2", "atribute 2");
	XML child3("childchild2", "atribute3");
	child2.addChild(child3);
	root.addChild(child2);
	List<XML> list5 = root.getChild();
	List<XML> list6 = list5[1].getChild();
	std::cout << list6[0].getAtribute() << std::endl;
	root.deleteAtribute("root/child2/childchild2");
	List<XML> list3 = root.getChild();
	List<XML> list4 = list3[1].getChild();
	std::cout << list4[0].getAtribute()<<"Atribute" << std::endl;
	root.printXML();

	return 0;
}