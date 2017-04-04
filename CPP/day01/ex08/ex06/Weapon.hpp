#ifndef WEAPON_H
# define WEAPON_H
# include <string>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon();
		std::string const & getType() const;
		void setType(std::string type);
	private:
		std::string _type;
};

#endif
