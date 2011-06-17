$(document).ready(function()
		{
			try
			{
				/* This connects sampleQObjects signal to our slot */
				/* sampleQObject.signal.connect(slot);  slot is a javascript function*/
				/* This calls a slot which then in turn emits the signal. */
				/* sampleQObject.slotThatEmitsSignal(); */
				dealWebkitEvent.hideDivById.connect(hideDivByIdJs);
				dealWebkitEvent.parserStatusesCounts.connect(setStatusesContent);
				dealWebkitEvent.setCommentsListHtml.connect(setHtmlById);
				
				
				dealWebkitEvent.setDomReady(new Boolean(true));
			}
			catch (e)
			{
				alert(e);
			}
		}
				 );
				 
function setHtmlById(htmlContent,id)
{
	var commentArea = document.getElementsByName(id+"_commentArea");
	for( i=0; i<commentArea.length; i++)
	{
		commentArea[i].innerHTML = htmlContent;
	}
}
				 
function setStatusesContent(jsonContent)
{
	var counts = eval(jsonContent);
	for(var i in counts)
	{
		if(counts[i].rt>0)
		{
			var retw=document.getElementsByName(counts[i].id+"_retw");
			for(j=0; j<retw.length; j++)
				retw[j].innerHTML += ("("+counts[i].rt+")");
		}
		if(counts[i].comments>0)
		{
			var tools=document.getElementsByName(counts[i].id+"_tool");
			for( k=0; k<tools.length; k++)
				tools[k].innerHTML += ("(<a href=javascript:void(0) onclick=showCommentsList(this,"+counts[i].id+",1) title=查看评论>"+counts[i].comments+"</a>)");
		}
	}
}

function showCommentsList(obj,id,page)
{
	try
	{
		var childs = obj.parentElement.parentElement.children;
		for( var child in childs )
		{
			var reValue = childs[child].nodeType;
			if(typeof(reValue)=="undefined")
				continue;
			if(childs[child].getAttribute("name")==(id+"_commentArea"))
			{
				if(childs[child].style.display=="block")
				{
					childs[child].style.display="none";
					
				}
				else
				{
					childs[child].style.display="block";
					dealWebkitEvent.getCommentsList(id,page);
				}
			}
		}
			} catch (e)
	{
		alert(e);
	}
}

function getMoreCommentsList(id,page)
{
	dealWebkitEvent.getCommentsList(id,page);
}

function hideDivByIdJs(id)
{
	document.getElementById(id).style.display="none";
}

function retw(idText, appendText) /* 转发 */
{
	dealWebkitEvent.retwStatusAction(idText, appendText);
}

function comment(id)
{
	dealWebkitEvent.commentStatus(id);
}

function replyComment(cid,id)
{
	dealWebkitEvent.replyComment(cid,id);
}

function openUrl(url)
{
	dealWebkitEvent.openUrl(url);
}

function addEmotion(phase)
{
	dealWebkitEvent.addEmotionPhase(phase);
}

function addFavorite(id)
{
	dealWebkitEvent.addFavorite(id);
}

function getUserTimelineByScreenName(screenName,page)
{
	dealWebkitEvent.getUserTimelineByScreenName(screenName,page);
}

function getUserTimeline(screenName,page)
{
	dealWebkitEvent.getUserTimelineByScreenName(screenName,page);
}

function bigPicture(orgUrl,midUrl)
{
	dealWebkitEvent.bigPicture(orgUrl,midUrl);
}

function getMoreHomePageStatus(page,feature)
{
	dealWebkitEvent.getMoreHomePageStatus(page,feature);
}

function getMoreUserPageStatus(page,feature)
{
	dealWebkitEvent.getMoreUserPageStatus(page,feature);
}

function getMoreAtMePageStatus(page)
{
	dealWebkitEvent.getMoreAtMePageStatus(page);
}

function getMoreCommentsPageStatus(page)
{
	dealWebkitEvent.getMoreCommentsPageStatus(page);
}

function getMoreFavoritePageStatus(page)
{
	dealWebkitEvent.getMoreFavoritePageStatus(page);
}

function getMoreDirectMessagePageStatus(page)
{
	dealWebkitEvent.getMoreDirectMessagePageStatus(page);
}

function deleteFavorite(id)
{
	dealWebkitEvent.deleteFavorite(id);
}

function deleteStatus(id)
{
	dealWebkitEvent.deleteMyStatus(id);
}

function sendDirectMessage(id)
{
	dealWebkitEvent.sendDirectMessage(id);
}

function trends(trendsName)
{
	dealWebkitEvent.openTrends(trendsName);
}