#include <iostream>
using namespace std;

class Intra {  // abstract
  private:
  public:
    std::string type;
    // std::string sbml_filename;
	
	// virtual void initialize_intracellular_from_pugixml(pugi::xml_node& node) = 0;
	virtual void start() = 0;
};
class Sbml : public Intra {  // concrete class
  private:
  public:

	void start() { cout << "sbml: start()\n"; } 
	// void initialize_intracellular_from_pugixml(pugi::xml_node& node);

};
class Pheno {
  private:
  public:
    Intra* imodel;

};
class Cell {
  private:
  public:
    Pheno p;
};

int main()
{
    Cell c;
    cout << "c.p.imodel ptr (initial Cell)= " << c.p.imodel << endl;  // Intra* pointer exists, but bogus
    Sbml s;
    s.type = "sbml";
    s.start();
    c.p.imodel = &s;
    cout << "c.p.imodel ptr (after assigning s)= " << c.p.imodel << endl;  
    cout << "c.p.imodel->type = " << c.p.imodel->type << endl;
}