
#include "Stage.h"

namespace Matheus
{
	class Stage2 :
		public Stage
	{
	public:
		Stage2(sf::RenderWindow& window, Player* P1, Player* P2);
		~Stage2();
	};
}
using namespace Matheus;