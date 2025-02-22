object MenuForm: TMenuForm
  Left = 0
  Top = 0
  Caption = 'MenuForm'
  ClientHeight = 468
  ClientWidth = 1064
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  OnResize = FormResize
  DesignSize = (
    1064
    468)
  TextHeight = 15
  object Label1: TLabel
    Left = 596
    Top = 11
    Width = 60
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'C'#259'utare'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ExplicitLeft = 600
  end
  object DBGrid1: TDBGrid
    AlignWithMargins = True
    Left = 8
    Top = 50
    Width = 1038
    Height = 410
    Anchors = [akLeft, akTop, akRight, akBottom]
    BorderStyle = bsNone
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentShowHint = False
    PopupMenu = PopupMenu1
    ReadOnly = True
    ShowHint = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid1DrawColumnCell
    OnKeyDown = DBGrid1KeyDown
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'pa_id'
        Title.Caption = 'ID'
        Visible = False
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'a_marca_model'
        ReadOnly = False
        Title.Caption = 'Marca'
        Width = 170
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'cod'
        ReadOnly = False
        Title.Caption = 'Cod'
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'nume_celula'
        ReadOnly = False
        Title.Caption = 'Celula'
        Width = 70
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'p_count'
        ReadOnly = False
        Title.Caption = 'Cantitatea'
        Width = 60
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'p_price'
        ReadOnly = False
        Title.Caption = 'Pre'#355
        Width = 80
        Visible = True
      end>
  end
  object AddButton: TButton
    Left = 908
    Top = 8
    Width = 120
    Height = 36
    Anchors = [akTop, akRight]
    Caption = 'Adaug'#259
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = AddButtonClick
    ExplicitLeft = 906
  end
  object SearchBox: TEdit
    Left = 676
    Top = 11
    Width = 201
    Height = 33
    Alignment = taCenter
    Anchors = [akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 25
    Font.Name = 'Segoe UI'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 2
    OnChange = SearchBoxChange
    OnClick = SearchBoxClick
    OnKeyDown = SearchBoxKeyDown
    ExplicitLeft = 674
  end
  object Button2: TButton
    Left = 8
    Top = 11
    Width = 144
    Height = 33
    Caption = #206'ncarc'#259' Datele din Fi'#351'ier'
    TabOrder = 3
    OnClick = Button2Click
  end
  object FDQuery1: TFDQuery
    AutoCalcFields = False
    CachedUpdates = True
    Connection = FDConnection1
    FormatOptions.AssignedValues = [fvSortOptions]
    UpdateOptions.AssignedValues = [uvCheckReadOnly, uvAutoCommitUpdates]
    SQL.Strings = (
      
        'SELECT pp.pa_id, a.a_marca_model, ct.cod, c.nume_celula, pp.p_co' +
        'unt, pp.p_price '
      'FROM product_auto_table pp '
      'JOIN vehicle_table a ON a.a_id = pp.a_id '
      'JOIN celula_table c ON c.id_celula = pp.celula_id '
      'JOIN code_table ct ON ct.id_cod = pp.id_cod;')
    Left = 600
    Top = 96
    object FDQuery1pa_id: TFDAutoIncField
      FieldName = 'pa_id'
      Origin = 'pa_id'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = False
    end
    object FDQuery1p_count: TLongWordField
      AutoGenerateValue = arDefault
      FieldName = 'p_count'
      Origin = 'p_count'
    end
    object FDQuery1p_price: TLongWordField
      AutoGenerateValue = arDefault
      FieldName = 'p_price'
      Origin = 'p_price'
    end
    object FDQuery1a_marca_model: TMemoField
      AutoGenerateValue = arDefault
      DisplayWidth = 10
      FieldName = 'a_marca_model'
      Origin = 'a_marca_model'
      ProviderFlags = []
      BlobType = ftMemo
      DisplayValue = dvFullText
    end
    object FDQuery1cod: TMemoField
      AutoGenerateValue = arDefault
      DisplayWidth = 20
      FieldName = 'cod'
      ProviderFlags = []
      BlobType = ftMemo
      DisplayValue = dvFullText
    end
    object FDQuery1nume_celula: TMemoField
      AutoGenerateValue = arDefault
      DisplayWidth = 20
      FieldName = 'nume_celula'
      BlobType = ftMemo
      DisplayValue = dvFullText
    end
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 592
    Top = 168
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'DriverID=MySQL'
      'Database=glasstrack_db'
      'Server=95.65.99.175'
      'User_Name=root'
      'Port=3306'
      'CharacterSet=cp1251'
      'Password=Halley2025!')
    UpdateOptions.AssignedValues = [uvAutoCommitUpdates]
    UpdateOptions.AutoCommitUpdates = True
    Left = 704
    Top = 160
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 'libmysql.dll'
    Left = 840
    Top = 160
  end
  object FDUpdateSQL1: TFDUpdateSQL
    Connection = FDConnection1
    Left = 728
    Top = 256
  end
  object PopupMenu1: TPopupMenu
    Left = 440
    Top = 8
    object MenuItemVinde: TMenuItem
      Caption = 'Vinde Produsul'
      OnClick = MenuItemVindeClick
    end
    object MenuItemEdit: TMenuItem
      Caption = 'Editeaz'#259' Produsul'
      OnClick = MenuItemEditClick
    end
  end
  object Timer1: TTimer
    Interval = 600000
    OnTimer = Timer1Timer
    Left = 928
    Top = 80
  end
end
