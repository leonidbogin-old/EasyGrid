object FormMain: TFormMain
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'EasyGrid'
  ClientHeight = 480
  ClientWidth = 585
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBoxStep1: TGroupBox
    Left = 11
    Top = 14
    Width = 561
    Height = 199
    Caption = #1064#1072#1075' 1 ('#1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080#1081'). '#1042#1099#1073#1086#1088' '#1075#1088#1072#1085#1080#1094' '#1089#1077#1090#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object GroupBoxPoint1: TGroupBox
      Left = 15
      Top = 30
      Width = 257
      Height = 107
      Caption = #1051#1077#1074#1099#1081' '#1074#1077#1088#1093#1085#1080#1081' '#1091#1075#1086#1083
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 19
        Top = 32
        Width = 77
        Height = 16
        Caption = #1064#1080#1088#1086#1090#1072' (Lat)'
      end
      object Label2: TLabel
        Left = 19
        Top = 66
        Width = 82
        Height = 16
        Caption = #1044#1086#1083#1075#1086#1090#1072' (Lon)'
      end
      object EditLat1: TEdit
        Left = 113
        Top = 30
        Width = 123
        Height = 22
        TabStop = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBtnText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object EditLon1: TEdit
        Left = 113
        Top = 64
        Width = 123
        Height = 22
        TabStop = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object GroupBoxPoint2: TGroupBox
      Left = 288
      Top = 30
      Width = 257
      Height = 107
      Caption = #1055#1088#1072#1074#1099#1081' '#1085#1080#1078#1085#1080#1081' '#1091#1075#1086#1083
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Label3: TLabel
        Left = 18
        Top = 32
        Width = 77
        Height = 16
        Caption = #1064#1080#1088#1086#1090#1072' (Lat)'
      end
      object Label4: TLabel
        Left = 19
        Top = 66
        Width = 82
        Height = 16
        Caption = #1044#1086#1083#1075#1086#1090#1072' (Lon)'
      end
      object EditLat2: TEdit
        Left = 113
        Top = 30
        Width = 125
        Height = 22
        TabStop = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object EditLon2: TEdit
        Left = 113
        Top = 64
        Width = 125
        Height = 22
        TabStop = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object ButtonCopyСoordinates: TButton
      Left = 15
      Top = 149
      Width = 530
      Height = 33
      Caption = 
        #1055#1086#1074#1090#1086#1088#1085#1086' '#1089#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1086#1088#1076#1080#1085#1072#1090#1099' '#1080#1079' '#1074#1099#1076#1077#1083#1077#1085#1085#1086#1081' '#1086#1073#1083#1072#1089#1090#1080' SAS Planet' +
        '  '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 2
      TabStop = False
      OnClick = ButtonCopyСoordinatesClick
    end
  end
  object GroupBoxStep2: TGroupBox
    Left = 11
    Top = 231
    Width = 561
    Height = 117
    Caption = #1064#1072#1075' 2. '#1042#1099#1073#1086#1088' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074' '#1082#1074#1072#1076#1088#1072#1090#1072' '#1089#1077#1090#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Label5: TLabel
      Left = 27
      Top = 39
      Width = 330
      Height = 16
      Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1080#1083#1080' '#1074#1074#1077#1076#1080#1090#1077' '#1088#1072#1079#1084#1077#1088' '#1082#1074#1072#1076#1088#1072#1090#1072' '#1089#1077#1090#1082#1080' '#1074' '#1084#1077#1090#1088#1072#1093
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 27
      Top = 75
      Width = 198
      Height = 16
      Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1090#1080#1087' '#1086#1073#1086#1079#1085#1072#1095#1077#1085#1080#1103' '#1090#1086#1095#1077#1082
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object ComboBoxBoxSize: TComboBox
      Left = 373
      Top = 36
      Width = 67
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnChange = ComboBoxBoxSizeChange
      Items.Strings = (
        '50'
        '100'
        '200'
        '250'
        '500'
        '1000')
    end
    object ComboBoxPointsType: TComboBox
      Left = 242
      Top = 72
      Width = 198
      Height = 24
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnChange = ComboBoxPointsTypeChange
      Items.Strings = (
        #1040#1085#1075#1083#1080#1081#1089#1082#1080#1081' '#1072#1083#1092#1072#1074#1080#1090' (A1-Z1)'
        #1056#1091#1089#1089#1082#1080#1081' '#1072#1083#1092#1072#1074#1080#1090' ('#1040'1-'#1071'1)'
        #1063#1080#1089#1083#1086#1074#1086#1077' (1-1)')
    end
  end
  object GroupBoxStep3: TGroupBox
    Left = 16
    Top = 373
    Width = 561
    Height = 84
    Caption = #1064#1072#1075' 3. '#1057#1086#1079#1076#1072#1085#1080#1077' '#1092#1072#1081#1083#1072' '#1082#1086#1086#1088#1076#1080#1085#1072#1090#1085#1086#1081' '#1089#1077#1090#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object ButtonSave: TButton
      Left = 15
      Top = 30
      Width = 530
      Height = 33
      Caption = #1057#1086#1079#1076#1072#1090#1100' '#1092#1072#1081#1083' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic, fsUnderline]
      ParentFont = False
      TabOrder = 0
      OnClick = ButtonSaveClick
    end
    object ProgressBar: TProgressBar
      Left = 2
      Top = 75
      Width = 557
      Height = 7
      Align = alBottom
      Smooth = True
      MarqueeInterval = 100
      BarColor = clWhite
      BackgroundColor = clWhite
      Step = 1
      TabOrder = 1
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'gpx'
    FileName = 'grid'
    Filter = 'Grid file|*.gpx'
    Left = 499
    Top = 392
  end
end
