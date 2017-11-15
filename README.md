this is the structure of this project:


data
	data/gameobjects/items/
	data/gameobjects/spells/
	data/gameobjects/rooms/
	data/gameobjects/creatures/
	data/gameobjects/persons/
	data/gameobjects/players/	

	data/settings/

src
	interfaces/GameObject
	interfaces/GameObject->Item
	interfaces/GameObject->Spell
	interfaces/GameObject->Room
	interfaces/GameObject->LivingOrganism->Player
	interfaces/GameObject->LivingOrganism->Creature
	interfaces/GameObject->LivingOrganism->Person
	
	core/roomEnginge/
	core/userActions/
	core/fileActions/

	utils/

	settings/

	actions/player
	commands/Combat
	commands/Spells
	
	core/roomEngine
	core/personEngine


	persistenceLayer/xmlParser
	

