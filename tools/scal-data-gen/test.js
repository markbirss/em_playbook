const fetch = require('node-fetch');

var str = {"items":[{"content":"在往期 #11WeeksOfAndroid 系列文章中我们介绍了联系人和身份、隐私和安全、Android 11 兼容性、开发语言、Jetpack、Android 开发者工具，本期将聚焦 Google Play 应用分发与盈利。我们将为大家陆续带来 #11WeeksOfAndroid 内容，深入探讨 Android 的各个关键技术点，您不会错过任何重要内容。本期的 11 Weeks of Android 聚焦 Google Play 上应用的分发与盈利。我们秉持初心，持续优化 Android 平台。Google Play 与开发者密切合作，为数十亿 Android 用户提供了惊人的线上体验。从一","link":"http://mp.weixin.qq.com/s?__biz=MzAwODY4OTk2Mg%3D%3D&mid=2652062890&sn=ab68fd4aeded57377a8dedbac6a4a8e6&idx=1","title":"聚焦 Android 11: Google Play 应用分发与盈利","desc":"2020/8/17&nbsp;&nbsp;&nbsp;#Google Play"},{"content":"强化学习 (RL) 是一种用于训练智能体制定在复杂环境中成功的决策序列的常用方法。如机器人导航，智能体控制机器人寻找通往目标位置的路径；或者游戏玩法，希望能在最短时间内通关。Q-learning 和 actor-critic 等许多现代的成功 RL 算法都提出将 RL 问题简化为 约束满足 (Constraint-Satisfaction) 问题，即对环境中的每个可能“状态”都设定约束条件。例如，在基于视觉的机器人导航中，环境的“状态”对应于每个可能的摄像头输入。尽管实践中约束满足方法无处不在，但这一策略通常难以与现实世界的复杂环境相协调。在实践场景中（例如机器人导航），可能的 “状态“ 很多","link":"http://mp.weixin.qq.com/s?__biz=MzAwODY4OTk2Mg%3D%3D&mid=2652062766&sn=ac2f905a03068d7ade875aa993d5d57c&idx=1","title":"对偶性解法，赋予强化学习更多可能性！","desc":"2020/8/17&nbsp;&nbsp;&nbsp;#Google"},{"content":"\"开发者说・DTalk\" 活动自去年 4 月上线以来，目前已经收到数百篇优质内容的投稿，其中部分优秀作者已进入 GDE (谷歌开发技术专家)* 推荐流程。在此，我们由衷地感谢大家的积极参与！ 今年对每个人来说都是充满挑战的一年，大家的工作环境也许会不同，但创造的心不会变。我国网络视频用户规模达 8.5 亿*，越来越多的开发者也选择用视频的方式分享自己的开发心得与技巧。我们也开始通过 Bilibili 征集并分享一些技术视频内容，本次我们挑选了 5 篇视频内容，与大家分享。Kotlin 的 Lambda，大部分人学得连皮毛都不算作者 / 扔物线 内容简介 很多人因为 Lambda 而被 Kotl","link":"http://mp.weixin.qq.com/s?__biz=MzAwODY4OTk2Mg%3D%3D&mid=2652062753&sn=8aa069f8fe5de5180681926c696083b2&idx=1","title":"更多形式，更多分享，来自开发者说·DTalk","desc":"2020/8/15&nbsp;&nbsp;&nbsp;#开发者说・DTalk"}]}

fetch('http://192.168.40.173:8081/download', {
    method: 'post',
    body:    JSON.stringify(str),
    headers: { 'Content-Type': 'application/json' },
})