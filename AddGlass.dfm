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
    Left = 59
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
    Left = 46
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
    TabOrder = 0
    OnExit = AutoComboBoxExit
    OnKeyPress = AutoComboBoxKeyPress
    OnSelect = AutoComboBoxSelect
  end
  object CountEdit: TEdit
    Left = 139
    Top = 159
    Width = 235
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object PriceEdit: TEdit
    Left = 139
    Top = 207
    Width = 235
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object AddButton: TButton
    Left = 245
    Top = 269
    Width = 97
    Height = 33
    Caption = 'Adaug'#259
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = AddButtonClick
  end
  object CancelButton: TButton
    Left = 60
    Top = 269
    Width = 91
    Height = 33
    Cancel = True
    Caption = 'Anuleaz'#259
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = CancelButtonClick
  end
  object CelulaComboBox: TComboBox
    Left = 139
    Top = 116
    Width = 235
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
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
    TabOrder = 6
    OnExit = CodComboBoxExit
    OnKeyPress = CodComboBoxKeyPress
    OnSelect = CodComboBoxSelect
  end
  object FDQuery1: TFDQuery
    Top = 464
  end
end
