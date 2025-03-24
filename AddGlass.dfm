object AddFormG: TAddFormG
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Ad'#259'gare Produs'
  ClientHeight = 311
  ClientWidth = 428
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  Scaled = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  TextHeight = 15
  object Label1: TLabel
    Left = 31
    Top = 70
    Width = 85
    Height = 25
    Caption = 'Automobil'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 57
    Top = 23
    Width = 33
    Height = 25
    Caption = 'Cod'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object TLabel
    Left = 30
    Top = 158
    Width = 79
    Height = 25
    Caption = 'Cantitatea'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object TLabel
    Left = 57
    Top = 206
    Width = 31
    Height = 25
    Caption = 'Pre'#355
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 47
    Top = 115
    Width = 47
    Height = 25
    Caption = 'Celula'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 232
    Top = 206
    Width = 37
    Height = 25
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = 'MDL'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object AutoComboBox: TComboBox
    Left = 139
    Top = 71
    Width = 235
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnExit = AutoComboBoxExit
    OnKeyPress = AutoComboBoxKeyPress
    OnSelect = AutoComboBoxSelect
  end
  object CountEdit: TEdit
    Left = 139
    Top = 159
    Width = 86
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object PriceEdit: TEdit
    Left = 139
    Top = 207
    Width = 86
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object AddButton: TButton
    Left = 261
    Top = 269
    Width = 97
    Height = 33
    Cursor = crHandPoint
    Caption = 'Adaug'#259
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = AddButtonClick
  end
  object CancelButton: TButton
    Left = 76
    Top = 269
    Width = 91
    Height = 33
    Cursor = crHandPoint
    Cancel = True
    Caption = 'Anulare'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = CancelButtonClick
  end
  object CelulaComboBox: TComboBox
    Left = 139
    Top = 116
    Width = 86
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object CodComboBox: TComboBox
    Left = 139
    Top = 24
    Width = 235
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnExit = CodComboBoxExit
    OnKeyPress = CodComboBoxKeyPress
    OnSelect = CodComboBoxSelect
  end
  object FDQuery1: TFDQuery
    Top = 464
  end
end
