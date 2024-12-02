#ifndef SISTINFO_H

#define SISTINFO_H

#include <string>
#include <vector>

using namespace std;

class SistInfo{
	private:
		static const vector <string> members;
		static const string discipline;
		static const string advisor;
		static const string group;
		static const string university;
		static const string release;
		static const string compilationVersion;
		static const string version;
		static const string barLine;
		static const string helpFile;

	public:

		    static const vector<string>& getMembers();
		    static const string& getDiscipline();
		    static const string& getAdvisor();
		    static const string& getGroup();
		    static const string& getUniversity();
		    static const string& getRelease();
			static const string& getBarLine();
			static const string& getVersion();
			static const string& getCompilatedVersion();
			static const string& getHelpFile();

};
	



#endif
