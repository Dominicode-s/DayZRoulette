class RouletteHeadingMenu extends UIScriptedMenu {
    private Widget layoutRouletteRoot;
    private TextWidget m_RoulettePlayerName;
    private TextWidget m_RouletteHeadingTextWidget;    
    private ButtonWidget m_RouletteButtonWidget;
    private ButtonWidget m_RouletteCloseButtonWidget;

    private bool m_RouletteIsVisible;
    private bool m_RouletteHeadingVisible = false;


    override Widget Init()
    {
        layoutRouletteRoot = GetGame().GetWorkspace().CreateWidgets("FirstModPacked/GUI/Layouts/RouletteLayout.layout"); //Set widget types
		m_RoulettePlayerName = TextWidget.Cast(layoutRouletteRoot.FindAnyWidget("RoulettePlayerName"));
        m_RouletteHeadingTextWidget = TextWidget.Cast(layoutRouletteRoot.FindAnyWidget("RouletteTextWidget"));
        m_RouletteButtonWidget = ButtonWidget.Cast(layoutRouletteRoot.FindAnyWidget("RouletteButton"));
        m_RouletteCloseButtonWidget = ButtonWidget.Cast(layoutRouletteRoot.FindAnyWidget("RouletteCloseButton"));
        // m_RouletteFrameWidget = m_RouletteHeadingRootWidget.FindAnyWidget ("FrameRoulette");
        m_RouletteIsVisible = false;
		m_RouletteButtonWidget.SetState(false);
		m_RouletteCloseButtonWidget.SetState(false);

        GetGame ().GetCallQueue (CALL_CATEGORY_GUI).CallLater (this.RouletteUpdate, 16, true);

        return layoutRouletteRoot;				
    }

    void RouletteUpdate () {
        m_RoulettePlayerName.SetText ("Welcome " + GetGame().GetPlayer().GetDisplayName());
        m_RouletteHeadingTextWidget.SetText ("Dominic's Lotto");
        m_RouletteButtonWidget.SetText ("Gamble your money!");
        layoutRouletteRoot.Update (); // This is where you set all the shit for the text

        if(m_RouletteIsVisible == 0 && GetGame ().GetPlayer ()) {
            HideCursorWidget(m_RouletteIsVisible);
        } else {
            HideCursorWidget(m_RouletteIsVisible);
        }

    }

    void HideCursorWidget(bool Visible) {
        if(Visible == 0){
            this.OnShow();
            layoutRouletteRoot.Show (true);
        } else {
            this.OnHide();
            layoutRouletteRoot.Show (false);
        }
    }

    void RouletteToggleHeading () {
        if (!m_RouletteIsVisible) {
            m_RouletteIsVisible = true;
        } else {
            m_RouletteIsVisible = false;
        }
    }

    override void OnShow() {
		super.OnShow();
		
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetInput().ChangeGameFocus(1);
		
	}
	
	override void OnHide() {
		super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(true);
		Close();
	}

    override bool OnClick( Widget w, int x, int y, int button ) {
		super.OnClick(w, x, y, button);
		Print(w);
		switch(w)
		{
			case m_RouletteButtonWidget:
				//RequestDeposit(m_EditBoxAmount.GetText().ToInt());  //Do stuff for lottry
                Print("Gamble Button");
				return true;
				break;
			
			case m_RouletteCloseButtonWidget:
				HideCursorWidget(1);
				return true;
				break;
		}
		return false;
	}

}