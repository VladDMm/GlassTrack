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
  object AddFileButton: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Alege Fi'#351'ier'
    TabOrder = 0
    OnClick = AddFileButtonClick
  end
  object PathEdit: TEdit
    Left = 96
    Top = 8
    Width = 289
    Height = 23
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 39
    Width = 1032
    Height = 362
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    ExplicitWidth = 1030
    ExplicitHeight = 354
  end
  object ConfirmButton: TButton
    Left = 490
    Top = 408
    Width = 121
    Height = 25
    Anchors = [akBottom]
    Caption = 'Confirm'#259' Ad'#259'ugarea'
    TabOrder = 3
    OnClick = ConfirmButtonClick
    ExplicitLeft = 489
    ExplicitTop = 400
  end
  object OpenDialog1: TOpenDialog
    Left = 592
    Top = 8
  end
end
