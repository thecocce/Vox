// ******************************************************************************
//
// Filename:	optionbox.h
// Project:     Vox
// Author:		Steven Ball
//
// Purpose:
//   An option box (radio button) GUI widget
//
// Revision History:
//   Initial Revision - 02/02/08
//
// Copyright (c) 2005-2006, Steven Ball
//
// ******************************************************************************

#pragma once

#include "abstractbutton.h"


class OptionBox : public AbstractButton, public MouseListener
{
public:
	/* Public methods */
	OptionBox(Renderer* pRenderer, unsigned int GUIFont, const std::string &label);
	OptionBox(Renderer* pRenderer, unsigned int GUIFont, unsigned int OutlineGUIFont, const std::string &label, Colour fontColour, Colour outlineColour);
	OptionBox(Renderer* pRenderer, unsigned int GUIFont, const std::string &label, const std::string &defaultTexture, const std::string &selectedTexture, const std::string &hoverTexture, const std::string &disabledTexture,
																						const std::string &toggledTexture, const std::string &toggledSelectedTexture, const std::string &toggledHoverTexture, const std::string &toggledDisabledTexture);

	~OptionBox();

	void AddEventListeners();
	void RemoveEventListeners();

	void RemoveIcon(RenderRectangle *pRemoveIcon);
	void SetDefaultIcons(Renderer* pRenderer);
	void SetToggledIcon(RenderRectangle *icon);
	void SetToggledSelectedIcon(RenderRectangle *icon);
	void SetToggledHoverIcon(RenderRectangle *icon);
	void SetToggledDisabledIcon(RenderRectangle *icon);

	void SetDimensions(int x, int y, int width, int height);
	void SetDimensions(const Dimensions& r);

	void SetLabelOffset(int x, int y);
	void SetLabelPosition(int x, int y);

	void SetPressedOffset(int x, int y);

	void SetLabelColour(Colour color);
	void SetNormalLabelColour(Colour normal);
	void SetHoverLabelColour(Colour hover);
	void SetPressedLabelColour(Colour pressed);	

	bool GetToggled() const;
	void SetToggled(bool toggle);

	EComponentType GetComponentType() const;

protected:
	/* Protected methods */
	void MouseEntered(const MouseEvent& lEvent);
	void MouseExited(const MouseEvent& lEvent);
	void MousePressed(const MouseEvent& lEvent);
	void MouseReleased(const MouseEvent& lEvent);
	void MouseClicked(const MouseEvent& lEvent);

	virtual void OnMouseEnter();
	virtual void OnMouseExit();
	virtual void OnMousePressed();
	virtual void OnMouseReleased();
	virtual void OnMouseClicked();

	void DrawSelf();

private: 
	/* Private methods */


public:
	/* Public members */

protected:
	/* Protected members */

private:
	/* Private members */
	RenderRectangle *m_pToggledIcon;
	RenderRectangle *m_pToggledSelectedIcon;
	RenderRectangle *m_pToggledHoverIcon;
	RenderRectangle *m_pToggledDisabledIcon;

	bool m_bToggled;

	int m_pressedOffsetX;
	int m_pressedOffsetY;
	bool m_offsetApplied;

	bool m_bChangeLabelText;
	Colour m_normalLabelColour;
	Colour m_hoverLabelColour;
	Colour m_PressedLabelColour;
};
