#include "script_component.hpp"

class FETT_vdDialog {
	idd = -1;
	movingEnable = 0;
	onLoad = "['init',_this] call FETT_vd_fnc_dialog;";
	class controls {
		class group {
			idc = -1;
			x = 0.432969 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.134062 * safezoneW;
			h = 0.209 * safezoneH;
			class VScrollbar {
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				shadow = 0;
				scrollSpeed = 0.06;
				width = 0;
				autoScrollEnabled = 1;
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
			};
			class HScrollbar {
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				shadow = 0;
				scrollSpeed = 0.06;
				height = 0;
				autoScrollEnabled = 0;
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
			};
			type = 15;
			shadow = 0;
			style = 16;
			class controls {
				class Title
				{
					idc = IDC_TITLE;
					text = "Sichtweite";
					style = 2;
					x = 0.005156 * safezoneW;
					y = 0.011 * safezoneH;
					w = 0.12375 * safezoneW;
					h = 0.022 * safezoneH;
					type = 0;
					colorBackground[] = {0,0,0,0};
					colorText[] = {1,1,1,1};
					fixedWidth = 0;
					shadow = 1;
					colorShadow[] = {0,0,0,0.5};
					font = "PuristaMedium";
					SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
					linespacing = 1;
					tooltipColorText[] = {1,1,1,1};
					tooltipColorBox[] = {1,1,1,1};
					tooltipColorShade[] = {0,0,0,0.65};
				};
				class Slider
				{
					idc = IDC_SLIDER;
					x = 0.005156 * safezoneW;
					y = 0.044 * safezoneH;
					w = 0.12375 * safezoneW;
					h = 0.022 * safezoneH;
					type = 3;
					style = 1024;
					color[] = {1,1,1,1};
					colorActive[] = {1,1,1,1};
					shadow = 0;
					onSliderPosChanged = "['vd',_this] call FETT_vd_fnc_dialog;";
				};
				class Title_1
				{
					idc = IDC_TITLE_1;
					text = "Objektsichtweite";
					style = 2;
					x = 0.005156 * safezoneW;
					y = 0.077 * safezoneH;
					w = 0.12375 * safezoneW;
					h = 0.022 * safezoneH;
					type = 0;
					colorBackground[] = {0,0,0,0};
					colorText[] = {1,1,1,1};
					fixedWidth = 0;
					shadow = 1;
					colorShadow[] = {0,0,0,0.5};
					font = "PuristaMedium";
					SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
					linespacing = 1;
					tooltipColorText[] = {1,1,1,1};
					tooltipColorBox[] = {1,1,1,1};
					tooltipColorShade[] = {0,0,0,0.65};
				};
				class Slider_1
				{
					idc = IDC_SLIDER_1;
					x = 0.005156 * safezoneW;
					y = 0.11 * safezoneH;
					w = 0.12375 * safezoneW;
					h = 0.022 * safezoneH;
					type = 3;
					style = 1024;
					color[] = {1,1,1,1};
					colorActive[] = {1,1,1,1};
					shadow = 0;
					onSliderPosChanged = "['ovd',_this] call FETT_vd_fnc_dialog;";
				};
				class Title_2
				{
					idc = -1;
					text = "Graseinstellungen";
					style = 2;
					x = 0.005156 * safezoneW;
					y = 0.143 * safezoneH;
					w = 0.12375 * safezoneW;
					h = 0.022 * safezoneH;
					type = 0;
					colorBackground[] = {0,0,0,0};
					colorText[] = {1,1,1,1};
					fixedWidth = 0;
					shadow = 1;
					colorShadow[] = {0,0,0,0.5};
					font = "PuristaMedium";
					SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
					linespacing = 1;
					tooltipColorText[] = {1,1,1,1};
					tooltipColorBox[] = {1,1,1,1};
					tooltipColorShade[] = {0,0,0,0.65};
				};
				class Toolbox
				{
					idc = IDC_XLISTBOX;
					x = 0.005156 * safezoneW;
					y = 0.176 * safezoneH;
					w = 0.12375 * safezoneW;
					h = 0.022 * safezoneH;

					style = "0x400 + 0x00 +	0x10";
					shadow = 2;
					type = 42;
					arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
					arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
					border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
					color[] = {1,1,1,0.6};
					colorActive[] = {1,1,1,1};
					colorDisabled[] = {1,1,1,0.25};
					colorPictudeDisabled[] = {1,1,1,0.25};
					colorPicture[] = {1,1,1,1};
					colorPictureDisabled[] = {1,1,1,1};
					colorSelect[] = {0.95,0.95,0.95,1};
					colorText[] = {1,1,1,1.0};
					deletable = 0;
					fade = 0;
					font = "PuristaMedium";
					sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
					soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1};
					tooltipColorText[] = {1,1,1,1};
					tooltipColorBox[] = {1,1,1,1};
					tooltipColorShade[] = {0,0,0,0.65};

			        onLBSelChanged = "['terrain',_this] call FETT_vd_fnc_dialog;";
				};
			};
		};
	};
};
