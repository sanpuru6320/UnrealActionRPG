# UnrealActionRPG

C++ & Blueprintsで実装
破壊可能オブジェクト
敵
武器を持った敵
武器を持たない敵
片手用武器
回避
HP、スタミナ、Soul(敵死亡時にドロップ。カウントのみ)

## Edittorでの実装
Animation Montageでアニメーション実装(攻撃,死亡,装備,ヒットのリアクション)
BluePrints
State(Animation Blueprints)
Enhanced Input
Niagaraシステム
Motion Warping 
UI
Healthバー
Staminaバー
Soulバー
IK Rig(ダウンロードしたアニメーションをキャラクターに適用)
Control Rig(段差に応じて足の接地面を調整)
スケルトンの調整
## スクリプトでの実装
武器の当たり判定
敵のAI
死亡後攻撃停止
アイテムの取得
State(攻撃,,交戦,追跡,巡回)

## その他
AnimationはMixamoからダウンロードして使用
効果音はフリー素材を使用
