class RouletteHeadingMenu extends UIScriptedMenu {
    private Widget m_RouletteHeadingRootWidget;
    private TextWidget m_RoulettePlayerName;
    private TextWidget m_RouletteHeadingTextWidget;    
    private ButtonWidget m_RouletteButtonWidget;

    private bool m_RouletteIsVisible;
    private bool m_RouletteHeadingVisible = false;

    void RouletteHeadingMenu (bool visible) {
        m_RouletteHeadingRootWidget = GetGame ().GetWorkspace ().CreateWidgets ("FirstModPacked/GUI/Layouts/RouletteLayout.layout"); //Set widget types
        m_RoulettePlayerName = TextWidget.Cast (m_RouletteHeadingRootWidget.FindAnyWidget ("RoulettePlayerName"));
        m_RouletteHeadingTextWidget = TextWidget.Cast (m_RouletteHeadingRootWidget.FindAnyWidget ("RouletteTextWidget"));
        m_RouletteButtonWidget = ButtonWidget.Cast (m_RouletteHeadingRootWidget.FindAnyWidget ("RouletteButton"));

        // m_RouletteFrameWidget = m_RouletteHeadingRootWidget.FindAnyWidget ("FrameRoulette");
        m_RouletteIsVisible = false;

       GetGame ().GetCallQueue (CALL_CATEGORY_GUI).CallLater (this.RouletteUpdate, 16, true);
    }

    void ~RouletteHeadingMenu () {
        GetGame ().GetCallQueue (CALL_CATEGORY_GUI).Remove (this.RouletteUpdate);  
    // if (m_RouletteHeadingRootWidget != null) {
    //     m_RouletteHeadingRootWidget.Show (false);
    // }
    }

    void RouletteUpdate () {

        m_RoulettePlayerName.SetText ("Welcome " + GetGame().GetPlayer().GetDisplayName());
        m_RouletteHeadingTextWidget.SetText ("Dominic's Lotto");
        m_RouletteButtonWidget.SetText ("Gamble your money!");
        m_RouletteHeadingRootWidget.Update (); // This is where you set all the shit for the text

        if(m_RouletteIsVisible == 0 && GetGame ().GetPlayer ()) {
            GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
            GetGame().GetUIManager().ShowCursor(true);
            GetGame().GetInput().ChangeGameFocus(1);
            m_RouletteHeadingRootWidget.Show (true);
        } else {
            GetGame().GetUIManager().ShowCursor(false);
            GetGame().GetInput().ResetGameFocus();
            GetGame().GetMission().PlayerControlEnable(true);   
            m_RouletteHeadingRootWidget.Show (false);
        }

    }

    void RouletteToggleHeading () {
        if (!m_RouletteIsVisible) {
            m_RouletteIsVisible = true;
        } else {
            m_RouletteIsVisible = false;
        }
    }


    override void OnShow()
	{
		super.OnShow();
		
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);
		
		m_TextAmountInput.SetText("0");
		m_EditBoxAmount.SetText("0");
		m_PanelMessage.Show(false);
		
		RequestPlayerData();
	}
	
	override void OnHide()
	{
		super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
		Close();
	}

}