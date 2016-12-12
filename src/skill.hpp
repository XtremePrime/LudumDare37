#ifndef SKILL_HPP
#define SKILL_HPP

class Skill
{
private:
	int level = 1;
	std::string name;
	int pts_spent = 0;
public:
	Skill(std::string name){
		this->name = name;
		this->level = 1;
		this->pts_spent = 0;
	}

	int get_level(){return this->level;}
	std::string get_name(){return this->name;}
	int get_pts_spent(){return this->pts_spent;}

	void add_pts(int am){this->pts_spent+=am;}
	void level_up(){this->level++;}
	void reset_level(){this->level = 0;}
};

#endif // SKILL_HPP