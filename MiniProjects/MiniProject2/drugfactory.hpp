#include "drug.hpp"

class DrugFactory{

	public:
		DrugFactory(std::string path); // this seems necessary but wasn't included

		virtual Drug* makeDrug() = 0; // VIRTUAL factory method- lets your subclass define how something is produced
		virtual void shipDrug() = 0; // Make sure there's a way to update the drug warehouse, write to file
	
	protected:
		std::string drug_warehouse_path;
	
};
