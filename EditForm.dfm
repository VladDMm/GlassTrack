object EditFormProduct: TEditFormProduct
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Editare Produs'
  ClientHeight = 289
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  Scaled = False
  DesignSize = (
    455
    289)
  TextHeight = 15
  object Label1: TLabel
    Left = 60
    Top = 24
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
  object Label2: TLabel
    Left = 34
    Top = 66
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
    Left = 40
    Top = 154
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
  object Label5: TLabel
    Left = 60
    Top = 108
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
  object Label6: TLabel
    Left = 62
    Top = 197
    Width = 29
    Height = 25
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Pre'#355
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ExplicitWidth = 31
  end
  object CodEdit: TEdit
    Left = 142
    Top = 25
    Width = 243
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object AutoEdit: TEdit
    Left = 142
    Top = 67
    Width = 243
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object CountEdit: TEdit
    Left = 142
    Top = 155
    Width = 243
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object PriceEdit: TEdit
    Left = 142
    Top = 198
    Width = 235
    Height = 28
    Anchors = [akLeft, akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object CelulaEdit: TEdit
    Left = 140
    Top = 109
    Width = 245
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object ConfirmButton: TButton
    Left = 273
    Top = 246
    Width = 101
    Height = 35
    Anchors = [akBottom]
    Caption = 'Confirmare'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = ConfirmButtonClick
  end
  object CancelButton: TButton
    Left = 71
    Top = 246
    Width = 91
    Height = 35
    Anchors = [akBottom]
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
    OnKeyDown = CancelButtonKeyDown
  end
end
