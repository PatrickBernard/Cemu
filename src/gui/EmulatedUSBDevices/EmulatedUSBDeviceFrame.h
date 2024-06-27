#pragma once

#include <array>

#include <wx/dialog.h>
#include <wx/frame.h>

class wxBoxSizer;
class wxCheckBox;
class wxFlexGridSizer;
class wxNotebook;
class wxPanel;
class wxStaticBox;
class wxString;
class wxTextCtrl;

class EmulatedUSBDeviceFrame : public wxFrame {
  public:
	EmulatedUSBDeviceFrame(wxWindow* parent);
	~EmulatedUSBDeviceFrame();

  private:
	wxCheckBox* m_emulatePortal;
	std::array<wxTextCtrl*, 16> m_skylanderSlots;
	std::array<std::optional<std::tuple<uint8, uint16, uint16>>, 16> m_skySlots;

	wxPanel* AddSkylanderPage(wxNotebook* notebook);
	wxBoxSizer* AddSkylanderRow(uint8 row_number, wxStaticBox* box);
	void LoadSkylander(uint8 slot);
	void LoadSkylanderPath(uint8 slot, wxString path);
	void CreateSkylander(uint8 slot);
	void ClearSkylander(uint8 slot);
	void UpdateSkylanderEdits();
};
class CreateSkylanderDialog : public wxDialog {
  public:
	explicit CreateSkylanderDialog(wxWindow* parent, uint8 slot);
	wxString GetFilePath() const;

  protected:
	wxString m_filePath;
};