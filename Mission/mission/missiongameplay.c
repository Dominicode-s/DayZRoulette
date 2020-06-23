modded class MissionGameplay extends MissionBase {
	autoptr ref RouletteHeadingMenu m_RouletteHeadingMenu;

    override void OnUpdate (float timeslice) {
        super.OnUpdate (timeslice);

        if (GetUApi ()) {
            UAInput inp = GetUApi ().GetInputByName ("DomsToggle");

            if (inp && inp.LocalPress ()) {
                if (m_RouletteHeadingMenu) {
                    m_RouletteHeadingMenu.RouletteToggleHeading ();
                } else {
                    this.initSSMenu();
                }
            }
        }
    }

    void initSSMenu()
	{
		if (g_Game.GetUIManager().GetMenu() == NULL)
		{
			if (g_Game.GetMissionState() == DayZGame.MISSION_STATE_GAME && GetGame().GetMission().GetHud())
			{
				m_RouletteHeadingMenu = new RouletteHeadingMenu;			
				GetGame().GetUIManager().ShowScriptedMenu(m_RouletteHeadingMenu, NULL);
			}																					
		}										
	}
    
}