# UnrealActionRPG
## C++ & Blueprintsで実装
* 破壊可能オブジェクト
* 敵(武器を持った兵士,昆虫,モンスター)
* 片手用武器
* 回避
* ジャンプ
* HP、スタミナ、Soul(敵死亡時にドロップ。カウントのみ)

## Editorでの実装
* Animation Blueprintsでステートを元にアニメーション管理　(攻撃,死亡,装備,ヒットのリアクション)
* Animation Montageでアニメーションの設定,効果音,Motion Warpping,コリジョンのオンオフ,エフェクトなどの実装
* Enhanced Input　(キャラクターの各入力)
* Niagaraシステム　(エフェクトなど)
* Motion Warping　(攻撃時の方向転換)
* Blend Pose　(移動スピードなどの数値によってアニメーションの変化)
* UI　(HP、スタミナ、Soul)
* IK Rig　(Mixmaoからダウンロードしたアニメーションを3Dアセットのキャラクターに適用)
* Control Rig　(段差に応じて足の位置を調整)
* その他にスケルトンやアニメーションのの調整　(アニメーション時のずれ、クリッピングの修正など)
## スクリプト(C++)での実装
* 武器の当たり判定
* 敵のAI　(攻撃,,交戦,追跡,巡回)
* プレイヤー死亡判定
* アイテムの取得

## デモ動画
https://youtu.be/74V04Fq97qM

## その他
* AnimationはMixamoからダウンロードしたものと、フリーのキャラクターアセットから使用。
* 3DモデルはEpic Gameのマーケットプレイスからダウンロード
* 効果音はフリー素材を使用
* ダウンロードした各素材を含むと容量が１０G以上になるため、プロジェクトの内容すべてをGithubにはアップロードしていません。ですので、ここにアップロードしたものだけでは(主にモデルが)不足しています。


## 参照
https://www.udemy.com/course/unreal-engine-5-the-ultimate-game-developer-course/
