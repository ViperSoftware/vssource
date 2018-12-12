// general resource header file

#define IDB_ARROWUP                     101
#define IDB_ARROWDOWN                   102
#define IDB_ES_AUTOSET32                103
#define IDB_ES_BATCHCUT32               104
#define IDB_ES_DISPATCH                 105
#define IDB_ES_SAW32                    106
#define IDB_ES_TABLE32                  107

// Cursors  ********************************************************************

#define IDC_POINTER_COPY                105

// Menu / Toolbar command id assignments  **************************************

// Database navigation
#define IDM_DB_BEGIN                    32800
#define IDM_DB_SEARCH                   32801
#define IDM_DB_SAVEREC          32831
#define IDM_DB_ADDREC         32832
#define IDM_DB_FIRSTREC                 32833
#define IDM_DB_PREVREC                  32834
#define IDM_DB_FINDREC                  32835
#define IDM_DB_NEXTREC                  32836
#define IDM_DB_LASTREC                  32837
#define IDM_DB_DELREC                   32838
#define IDM_DB_LOADSCREEN       32839
#define IDM_DB_SYNC_CURRENT             32840
#define IDM_DB_END                      32899

#define IDM_JOB_SEARCH                  32799

#define ID_CONTEXT_PRINT                32701

#define CUSTOM_MENU_MINID       32500  // 32501 - 32599

// report menu command id range
#define IDM_REPORT_BEGIN          32900
#define ID_SHOP_IMPACT            32901
#define IDM_REPORT_END            32999

// JobScheduler
#define IDM_QUEUE_CREATE          32772
#define IDM_QUEUE_DELETE          32773
#define IDM_QUEUE_EDIT            32774
#define IDM_TIMELOG               32776
#define IDM_REPORTS               32777

// global common dialog resources  *********************************************

#define IDD_DB_FORMVIEW                 149

#define IDD_DB_SEARCH                   154
#define IDC_DB_SEARCH_FIELDS            1000
#define IDC_DB_SEARCH_KEY               1001


#define IDD_LISTVIEWS                   130
// List Views dialog fields
#define IDC_ADD_VIEW                    1000
#define IDC_EDIT_VIEW                   1001
#define IDC_DELETE_VIEW                 1002
#define IDC_SETDEFAULT                  1003
#define IDC_CLEARDEFAULT                1004
#define IDC_VIEWS_LIST                  1005

#define IDD_ADD_DEVICE                  115
// Add Device base dialog fields
#define IDC_TITLE                       1000
#define IDC_CAPACITY                    1001
#define IDC_DIRECTORY                   1002
#define IDC_TYPE                        1003
#define IDC_FILE_TYPE                   1004
#define IDC_STATUS                      1005
#define IDC_DIR_BROWSE                  1006
#define IDC_DEPT                        1007
#define IDC_PARAMS            1008

#define IDD_WORKORDER                   113
// Add WO base dialog fields
#define IDC_JOB                         1000
#define IDC_MARK                        1001
#define IDC_DEVICE                      1002
#define IDC_WO_ACTIVITY                 1008
#define IDC_SCHED_START                 1006
#define IDC_SCHED_STOP                  1007
#define IDC_RESOURCE                    1021
#define IDC_FILE                        1022
#define IDC_DUE_DATE                    1009
#define IDC_ACT_START                   1136
#define IDC_ACT_STOP                    1137
#define IDC_STOP_WO                     1139
#define IDC_START_WO                    1140


#define IDD_WORKORDER_GRID              114
#define IDD_EDIT_GRID         114
#define IDD_WORKORDER_DETAILS           1101 
// Edit WO details Grid
#define IDC_GRID                        1029
#define ID_CALC_WO_LABOR                1134  // special WO edit grid command button

#define IDD_SYMBOLTABLE                 145

#define IDD_FIND_WO                     147
// Find WO(s) dialog fields
#define IDC_LIST1                       1041
#define IDC_BUTTON1                     1105
#define IDC_MFCMASKEDEDIT2              1023

// WO Gantt
#define IDC_GANTT                       1071
#define IDC_PRINT                       1072

#define IDD_SCHEDULESHIFT               1100
// Schedule Shift dialog fields
#define IDC_SHIFT_NAME                  1000
#define IDC_SHIFT_LOCATION              1001
#define IDC_SHIFT_WEEKDAY               1002
#define IDC_SHIFT_START                 1003
#define IDC_SHIFT_BREAK1                1004
#define IDC_SHIFT_LUNCH                 1005
#define IDC_SHIFT_BREAK2                1006
#define IDC_SHIFT_STOP                  1007
#define IDC_SHIFT_BREAK1_LEN            1008
#define IDC_SHIFT_LUNCH_LEN             1009
#define IDC_SHIFT_BREAK2_LEN            1010

#define IDD_SHIFTS                      135
// Shift select/define dialog
#define IDC_SHIFT_ADD                   1000
#define IDC_SHIFT_DELETE                1001
#define IDC_SHIFT_ACTIVATE              1002
#define IDC_SHIFT_LIST                  1003
#define IDC_SHIFT_EDIT          1004

#define IDD_DBLIST_VIEWER               148
// DbExployer dialog fields
#define IDC_SELECT                      1000
#define IDC_SORT                        1001
#define IDC_FILTER                      1002
#define IDC_LISTDEF                     1003
#define IDC_DEFINE_FILTER               1004
#define IDC_DEFINE_SORT                 1005
#define IDC_DEFINE_LISTDEF              1006

#define IDD_DB_POPUP_LISTVIEW           138

#define IDR_BUTTON_MENU                 137
#define IDR_FINDWO_BUTTON_MENU          142
#define IDR_DEF_FORM_POPUP              144
#define IDR_DEF_CHART_POPUP             147

#define IDC_ACTIVITY_BUTTON             1100
#define IDC_REPORTS_BUTTON              1101
#define IDC_TABLE_BUTTON                1102
#define ID_ACTIONS_EDIT                 32775
#define ID_ACTIONS_EDITALL              32796
#define ID_ACTIONS_DELETE               32776
#define ID_ACTIONS_NEW                  32781
#define ID_ACTIONS_PRINT                32904
#define ID_ACTIONS_UNSCHEDULE           40077
#define IDM_WO_CALCLABOR                40065


// Window user message id assignments   ****************************************

#define WM_MOVETORECORD                         WM_USER + 100
#define WM_UPDATESCREEN                         WM_USER + 101
#define WM_UPDATETITLE                          WM_USER + 102
#define WM_ADDRECORD							WM_USER + 103
#define WM_MOVETOSUBRECORD                      WM_USER + 104
#define WM_ITEM_DCLICKED                        WM_USER + 105
#define WM_UNDOITEMACTIVATION					WM_USER + 106
#define WM_ITEMDROPPED                          WM_USER + 107
#define WM_UPDATE_DBLOOKUP_FIELDS				WM_USER + 108
#define WM_REQUERY_DATASOURCE					WM_USER + 109
#define WM_CLOSE_POPUP							WM_USER + 110
#define WM_ATTACH_PRINTDOC						WM_USER + 111
#define WM_UPDATE_DBLIST_FIELDS					WM_USER + 112
#define WM_ITEM_CLICKED							WM_USER + 113
#define WM_ITEM_RCLICKED						WM_USER + 114
#define WM_ITEM_ACTION							WM_USER + 115
#define WM_ViperCmdString						WM_USER + 116 
#define WM_ITEM_CHANGED							WM_USER + 117 
#define WM_DATASOURCE_SORTED					WM_USER + 118
#define WM_DATASOURCE_SORT						WM_USER + 119
#define WM_UPDATE_DBGRID_FIELDS					WM_USER + 120
#define WM_UPDATE_CALGRID_FIELDS				WM_USER + 121
