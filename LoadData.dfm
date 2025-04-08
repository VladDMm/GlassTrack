object LoadDataForm: TLoadDataForm
  Left = 0
  Top = 0
  Caption = 'Load Data'
  ClientHeight = 441
  ClientWidth = 1058
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  Position = poMainFormCenter
  OnKeyPress = FormKeyPress
  OnResize = FormResize
  DesignSize = (
    1058
    441)
  TextHeight = 15
  object Label1: TLabel
    Left = 446
    Top = 8
    Width = 86
    Height = 20
    Anchors = [akTop, akRight]
    Caption = 'Alege Printer'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ExplicitLeft = 456
  end
  object Label2: TLabel
    Left = 446
    Top = 46
    Width = 84
    Height = 20
    Anchors = [akTop, akRight]
    Caption = 'Num'#259'r Copii'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ExplicitLeft = 454
  end
  object Label3: TLabel
    Left = 626
    Top = 45
    Width = 160
    Height = 20
    Anchors = [akTop, akRight]
    Caption = 'Pre'#355' '#238'nvechit de la (lun'#259')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ExplicitLeft = 634
  end
  object Label4: TLabel
    Left = 855
    Top = 43
    Width = 63
    Height = 20
    Anchors = [akTop, akRight]
    Caption = 'Nivel Log'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ExplicitLeft = 863
  end
  object AddFileButton: TButton
    Left = 8
    Top = 23
    Width = 91
    Height = 25
    Caption = 'Alege Fi'#351'ier'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = AddFileButtonClick
  end
  object PathEdit: TEdit
    Left = 113
    Top = 21
    Width = 264
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 72
    Width = 1022
    Height = 330
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelInner = bvSpace
    BevelKind = bkFlat
    BevelOuter = bvSpace
    BorderStyle = bsNone
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    ExplicitWidth = 1024
  end
  object ConfirmButton: TButton
    Left = 461
    Top = 408
    Width = 159
    Height = 25
    Anchors = [akBottom]
    Caption = 'Confirm'#259' Modific'#259'rile'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = ConfirmButtonClick
    ExplicitLeft = 462
  end
  object PrinterComboBox: TComboBox
    Left = 548
    Top = 8
    Width = 189
    Height = 28
    Anchors = [akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object CopyCountEdit: TEdit
    Left = 548
    Top = 44
    Width = 49
    Height = 28
    Anchors = [akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    ExplicitLeft = 550
  end
  object ChangePassButton: TButton
    Left = 915
    Top = 8
    Width = 113
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Schimb'#259' Parola'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = ChangePassButtonClick
    ExplicitLeft = 917
  end
  object LEdit: TEdit
    Left = 792
    Top = 43
    Width = 46
    Height = 28
    Anchors = [akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    ExplicitLeft = 794
  end
  object LogLevelComboBox: TComboBox
    Left = 924
    Top = 40
    Width = 103
    Height = 28
    Anchors = [akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    Items.Strings = (
      '0 - None'
      '1 - Exception'
      '2 - Warning'
      '3 - Info'
      '4 - Debug'
      '5 - Trace')
  end
  object OpenDialog1: TOpenDialog
    Left = 424
    Top = 88
  end
end
