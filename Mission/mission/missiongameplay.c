modded class MissionGameplay extends MissionBase {
    ref RouletteHeadingMenu m_RouletteHeadingMenu;

    override void OnUpdate (float timeslice) {
        super.OnUpdate (timeslice);

        if (GetUApi ()) {
            UAInput inp = GetUApi ().GetInputByName ("DomsToggle");

            if (inp && inp.LocalPress ()) {
                if (m_RouletteHeadingMenu) {
					Print("2");
                    m_RouletteHeadingMenu.RouletteToggleHeading ();
                } else {
					Print("1");
                    m_RouletteHeadingMenu = new RouletteHeadingMenu (true);
                }
            }
        }
    }
}