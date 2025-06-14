#pragma once
class entity
{
	public:
		entity(bool _is_player, int _health) : is_player(_is_player), health(_health) {}
		~entity() {
			
		}
		void do_damage(int dmg) {
			if (target) {
				target->health -= dmg;
			}
		}
		int health;
		bool is_player;
		entity* target = nullptr;
};

