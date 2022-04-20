#include <string>
#include "drug.hpp"

class DrugFactory{

	public:
		virtual Drug* makeDrug() = 0; // VIRTUAL factory method- lets your subclass define how something is produced
		virtual void shipDrug() = 0; // Make sure there's a way to update the drug warehouse
	
	protected:
		std::string drug_warehouse_path;
	
};
