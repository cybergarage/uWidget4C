var modeNode = getNode('mode');
var funcNode = getNode('func');

// 起動時に呼ばれます
function onLoad() {
    setStr(funcNode, 'onLoad()');
    setStr(modeNode, 'Normal Mode');
}

// フォーカス・モード遷移時に呼ばれます
function onFocus() {
    setStr(funcNode, 'onFocus()');
    setStr(modeNode, 'Focus Mode');
}

// フォーカス・モードからノーマル・モードへの遷移時に呼ばれます
function onUnfocus() {
    setStr(funcNode, 'onUnfocus()');
    setStr(modeNode, 'Normal Mode');
}

// アクティブ・モード遷移時に呼ばれます
function onActivate() {
    setStr(funcNode, 'onActivate()');
    setStr(modeNode, 'Active Mode');
    loadImage(getNode('active-bg'), 'img/active-bg.png');
}

// 上キー押下時に呼ばれます(フォーカス/アクティブ・モード)
function onUpKey() {
    setStr(funcNode, 'onUpKey()');
}

// 下キー押下時に呼ばれます(フォーカス/アクティブ・モード)
function onDownKey() {
    setStr(funcNode, 'onDownKey()');
}

// 右キー押下時に呼ばれます(フォーカス/アクティブ・モード)
function onRightKey() {
    setStr(funcNode, 'onRightKey()');
}

// 左キー押下時に呼ばれます(フォーカス/アクティブ・モード)
function onLeftKey() {
    setStr(funcNode, 'onLeftKey() ');
}

// 決定キー押下時に呼ばれます(アクティブ・モード)
// type : 0 pressed, 1 released
function onConfirmKey(type) {
    setStr(funcNode, 'onConfirmKey(' + type + ')');
}

