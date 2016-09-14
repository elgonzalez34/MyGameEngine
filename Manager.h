#pragma once
#include <stdlib.h>
#include <string>

namespace df {

	class Manager
	{
	private:
		std::string type;		//identifies the type of Manager
		bool is_started;		//Whether or not is has started

	protected:
		void setType(std::string type);

	public:
		Manager();
		virtual ~Manager();
		//Getter for type
		std::string getType() const;		
		// Creates manager
		virtual int startUp();				
		//Shuts down manager
		virtual void shutDown();			
		//Returns true if started
		bool isStarted() const;
	};
}

